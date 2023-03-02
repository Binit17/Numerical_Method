//langrange's interpolation method
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    cout<<setprecision(4)<<fixed;
    int n;
    float xp,x[10],y[10];
    float sum=0;
    cout<<"enter the no. of datas: ";cin>>n;
    cout<<"enter xp: ";cin>>xp;
    cout<<"enter the values of x and y: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]: ";cin>>x[i];
        cout<<"y["<<i<<"]: ";cin>>y[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t";
        cout<<y[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        float product =1;
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
                product*=(xp-x[j]/(x[i]-x[j]));
            }
        }
        // product*=y[i];
        sum=sum+product*y[i];
    }
    cout<<"\n solution is: "<<sum;
    return 0;
}