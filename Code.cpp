#include<iostream>
using namespace std;

int su_in[9][9]={
                 0,0,7   ,0,0,0    ,4,0,6,
                 8,0,0   ,4,0,0    ,1,7,0,
                 0,0,0   ,3,0,0    ,9,0,5,
                 
                 0,0,0   ,7,0,5    ,0,0,8,
                 0,0,0   ,0,0,0    ,0,0,0,
                 4,0,0   ,2,0,8    ,0,0,0,
                 
                 7,0,4   ,0,0,3    ,0,0,0,
                 0,5,2   ,0,0,1    ,0,0,9,
                 1,0,8   ,0,0,0    ,6,0,0   
                };
int su_out[9][9];/*={


                 5,3,7   ,9,1,2    ,4,8,6,
                 8,2,9   ,4,5,6    ,1,7,3,
                 6,4,1   ,3,8,7    ,9,2,5,
                 
                 9,1,3   ,7,4,5    ,2,6,8,
                 2,8,6   ,1,3,9    ,7,5,4,
                 4,7,5   ,2,6,8    ,3,9,1,
                 
                 7,6,4   ,8,9,3    ,5,1,2,
                 3,5,2   ,6,7,1    ,8,4,9,
                 1,9,8   ,5,2,4    ,6,3,7
                };*/
            
struct chance{
    
    int poss[9];
    
};              
                
int box_validate(int,int,int);
void read(int);
void display(int);
int validate(int);
int solve();

int main()
{   
    int i,j,row,get_res=2;
    
    enum {input=1,output};
    
    cout<<"enter the sudoku: use 0 if the colum is empty:\n";
    
//  for(i=0; i<9; i++){
//  read(i);
//  }
    
    cout<<"\n\t\tTHE ENTERED SU-DO-CU IS:\n\n";
    display(input);
    
    get_res=validate(input);
    
    if(get_res==0)
        cout<<"valid input!\n";
        else if(get_res==1)
           cout<<"invalid input!\n";

//  display(input);
    for(i=0; i<9; i++)
    for(j=0; j<9; j++)
    su_out[i][j]=su_in[i][j];
    
//  display(output);
    get_res=validate(output);
    
    if(get_res==0){
        cout<<"valid solution!\n"; display(output);}
    //  else if(get_res==1)
    //     cout<<"invalid sudoku!\n";
    
    if(solve()==0) display(output);
    else cout<<"not solved buddy!!\n";


}




void read(int row) // function to read the SU-DO-CU
{   
    unsigned num,i;
    cout<<"enter the row:'"<<row+1<<"'\n";
    
    for(i=0; i<9;   i++)
    {
    cin>>num;
    if(num<0||num>9)
    cout<<"error! invalid input: enter a number < or = 9 and > or = 0 \n";
    else
    su_in[row][i]=num;
    }
}


void display(int sudoku) // function to display the SU-DO-CU
{
    unsigned i,j;
    
        for(i=0;i<9; i++)
        {   
            if(i%3==0)
            cout<<"\t\t-------------------------\n";    
            
            cout<<"\t\t";
            for(j=0; j<9; j++)
                {   
                    if(j%3==0)
                    cout<<"| ";
            
            //      if(su[i][j]==0)
            //      cout<<"_ ";
            //      else    
                    if(sudoku==1)
                    cout<<su_in[i][j]<<" ";
                    
                    else if(sudoku==2)
                    cout<<su_out[i][j]<<" ";
                    
                    if(j==8)
                    cout<<"|";  
                    
                }
                
            cout<<"\n";
            if(i==8)
            cout<<"\t\t-------------------------\n";    
            
        
        }
        
        
}


int validate(int sudoku) // function to validate the input SU-DO-CU
{
    unsigned i,j,k,n,count=0;
//..........................row validation
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            for(k=0;k<9;k++)
                {
                    if(sudoku==1 && k!=j && su_in[i][j]!=0)
                       {
                        if(su_in[i][j]==su_in[i][k])
                        return 1;
                       }
                     else if(sudoku==2 && k!=j )
                       {
                        if(su_out[i][j]==su_out[i][k])
                        return 1;
                       }  
            
                    
                }
//..................................colume validation
    for(i=0;  i<9;  i++)
        for(j=0;  j<9;  j++)
            for(k=0;  k<9;  k++)
                {
                    if(sudoku==1 && k!=j && su_in[j][i]!=0)
                       {
                        if(su_in[j][i]==su_in[k][i])
                        return 1;
                       }
                     else if(sudoku==2 && k!=i )
                       {
                        if(su_out[j][i]==su_out[j][k])
                        
                        return 1;
                       }    
                }
    // each box validating.......................
    for(i=0;  i<=6;  i=i+3)
        for(j=0; j<=6; j=j+3)
        {
            if(box_validate(i,j,sudoku)==1)
            return 1;
        }
    
    // sum validation for output....
    
    if(sudoku==2)
    {
        for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            count=count+su_out[i][j];
        
    if(count!=405) return 1;
    }
    
    
        return 0;           
                
}


int box_validate(int i,int j,int sudoku)
{   
    unsigned k=j,n=i;
    int temp_i=i,temp_j=j,temp_k=k, temp_n=n;
        for(i=temp_i;  i<temp_i+3;  i++)
        for(j=temp_j;  j<temp_j+3;  j++)
            for(k=temp_k;  k<temp_k+3;  k++)
                {           
                  if(sudoku==1 && k!=j && su_in[i][j]!=0)
                 {
                    if(su_in[i][j]==su_in[i][k])
                     return 1;
                    
                        for(n=temp_n;  n<temp_n+3;  n++)
                        {
                             if(sudoku==1 &&  su_in[i][j]!=0)
                              if(k==j && n==i)
                                ;else 
                                  if(su_in[i][j]==su_in[n][k])
                                    return 1;
                                
                        }
                }
        

                if(sudoku==2 && k!=j )
                {
                    if(su_out[i][j]==su_out[i][k])
                     return 1;
                    
                        for(n=temp_n;  n<temp_n+3;  n++)
                        {
                             if(sudoku==1 )
                              if(k==j && n==i)
                                ;else 
                                  if(su_out[i][j]==su_out[n][k])
                                    return 1;
                                
                        

                          }
                }
            }
    return 0;
    
}


int solve()
{
    unsigned i,j,k,m,n,x;   

struct chance cell[9][9];

    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            if(su_in[i][j]==0)
                for(k=0;k<9; k++)
                cell[i][j].poss[k]=k+1;
                
                /*
    for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            if(su_in[i][j]==0)
                for(k=0;k<9; k++)
                {   su_out[i][j]=cell[i][j].poss[k]=k+1;            
                        su_out[i][j]=cell[i][j].poss[k];
                        for(m=0; m<9; m++)
                          for(n=0; n<9; n++)
                          for(x=1; x<=9; x++)
                          { if(x!=k+1)
                            cell[m][n].poss[x]==x;
                            if(validate(2)==0)
                               return 0;
                       }
            }*/
            
        for(i=0; i<9; i++)
        for(j=0; j<9; j++)
            if(su_in[i][j]==0)
            while (validate(2)==0)
            {
            
                for(k=0;k<9; k++)
                {   su_out[i][j]=k+1;           
                        for(m=i+1; m <9 ; m++)
                          for(n=0; n <9 ; n++)
                            for(x=1; x<=9; x++)
                          { su_out[m][n]=x;
                            if(validate(2)==0)
                               return 0;
                       }
            }
          }
}
