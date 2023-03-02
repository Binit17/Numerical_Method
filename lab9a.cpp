//trapezoidal rule
#include<iostream>
#include<cmath>
#include<array>
using namespace std;

void trapezoidal(float *x,float *y,int n)
{
    float h = x[1]-x[0];
    float sum1;float sum2=0;
    sum1=y[0]+y[n-1];
    for (int i = 1; i < n-1; i++)
    {
        sum2+=y[i];
    }
    float ans = h*(sum1+2*sum2)/2;
    cout<<"integral value: "<<ans;
}
int main()
{
    int n; float x[10],y[10];
    cout<<"enter the no. of datas: ";cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"x["<<i<<"]: ";cin>>x[i];
        cout<<"y["<<i<<"]: ";cin>>y[i];
    }
    trapezoidal(x,y,n);
}