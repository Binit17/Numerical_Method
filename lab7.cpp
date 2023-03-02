#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    cout<<setprecision(4)<<fixed;
    int n,d;
    cout<<"enter the degree of equation: ";
    cin>>d;
    n=d+1;
    float x[n],y[n];
    float aug[d+1][d+1];
    cout<<"enter the values for x: ";
    for (int i = 0; i < n; i++)
    {
        cout<<"x["<<i<<"]: ";
        cin>>x[i];
    }
    cout<<"enter the values for y: ";
    for (int i = 0; i < n; i++)
    {
        cout<<"y["<<i<<"]: ";
        cin>>y[i];
    }
    //constructing the augmented matrix
    for (int i = 0; i <=d; i++)
    {
        for (int j = 0; j <= d; j++)
        {
            aug[i][j]=0;
            for (int k = 0; k <=(n-1); k++)
            {
                aug[i][j]+=pow(x[k],i+j);
            }   
        }
        aug[i][d]=0;
        for (int k = 0; k<=(n-1); k++)
        {
            aug[i][d]+=(pow(x[k],i)*y[k]);
        }
    }
    //printing the matrix:
    for(int i=0; i<d;i++)
    {
        for(int j=0;j<=d;j++)
        {
            cout<<aug[i][j]<<"\t";
        }
        cout<<endl;
    }
    //using gauss jordan method.
    for(int j=0;j<d;j++)
    {
        if(aug[j][j] == 0.0)
			  {
				   cout<<"Mathematical Error!";
				   exit(0);
			  }
        for(int i=0;i<d;i++)
        {
            if (i!=j)
            {
                float ratio = aug[i][j]/aug[j][j];
                for (int k = 0; k<=d; k++)
                {
                    aug[i][k]=aug[i][k]-ratio*aug[j][k];
                }
            }
        }
    }
    cout<<endl;
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<=d;j++)
        {
            cout<<aug[i][j]<<"\t";
        }
        cout<<endl;
    }
    //printing the output
    for (int i = 0; i < d; i++)
    {
        cout<<"c["<<i<<"]]"<<aug[i][d]/aug[i][i]<<endl;
    }
    return 0;
}
