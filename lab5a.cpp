// GAUSS JORDAN METHOD 

#include<iostream>
using namespace std;

int main()
{
    int n;
    float arr[10][10];
    cout<<"enter the number of unknowns: ";
    cin>>n;
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
            if(i!=j)
            {
                float ratio = arr[i][j]/arr[j][j];
                for (int k = 1; k <= n+1; k++)
                {
                   arr[i][k]=arr[i][k] - (ratio * arr[j][k]);
                }   
            }
        }   
    }
    cout<<"\ndiagonal matrix: "<<endl;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n+1; j++)
        {
            // cout<<"arr["<<i<<"]"<<"["<<j<<"]: ";
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"\nsolutions are: "<<endl;
    for (int i = 1; i <=n; i++)
    {
        cout<<arr[i][n+1]/arr[i][i]<<endl;
    }
    
    return 0;
}