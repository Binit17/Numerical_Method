// GAUSS ELIMINATION METHOD 

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter the number of unknowns: ";
    cin>>n;
    float arr[n+1][n+2],res[n+1];
    cout<<"enter the values of matrix: "<<endl;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n+1; j++)
        {
            cout<<"arr["<<i<<"]"<<"["<<j<<"]: ";
            cin>>arr[i][j];
        }
    }
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n+1; j++)
        {
            // cout<<"arr["<<i<<"]"<<"["<<j<<"]: ";
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    for (int j = 1;  j<= n ; j++)
    {
        for (int i = 1; i <=n; i++)
        {
            if(i>j)
            {
                float ratio = arr[i][j]/arr[j][j];
                for (int k = 1; k <= n+1; k++)
                {
                   arr[i][k]=arr[i][k] - (ratio * arr[j][k]);
                }   
            }
        }   
    }
    cout<<"\nupper triangular matrix: "<<endl;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n+1; j++)
        {
            // cout<<"arr["<<i<<"]"<<"["<<j<<"]: ";
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    /* Backward substitution for discovering values of unknowns */
    for(int i=n;i>0;i--)          
    {                     
        res[i]=arr[i][n+1];
                    
        for(int j=i+1;j<n+1;j++)
        {
            if(i!=j)
            {
              res[i]=res[i]-arr[i][j]*res[j];
            }          
        }
        res[i]=res[i]/arr[i][i];  
    }
    
    cout<<"\nsolutions are: "<<endl;
    for(int i=1;i<=n;i++)
    {
      cout<<res[i]<<"\n";
    }
    
    return 0;
}