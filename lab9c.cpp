///simpson 3/8 rule
#include<iostream>
#include<cmath>
using namespace std;

float fn(float x)
{return (1/(1+x*x));}
float integral(float x0,float xn)
{return atan(xn)-atan(x0);}
void simpson8(float x0,float xn,float h, float n)
{
    float actual=integral(x0,xn);
    float sum1=0;float sum2=0;float sum3=0;
    sum1=fn(x0)+fn(xn);
    float x=x0;
    for (int i = 1; i < n; i++)
    {
        x=x+h;
        if(i%3==0){
            sum2+=fn(x);
        }
        else{
            sum3+=fn(x);
        }        
    }cout<<sum2<<endl<<sum3<<endl;
    float ans=(h*(sum1+2*sum2+3*sum3))*3/8;
    cout<<"\nintegral from simpson 1/3: "<<ans;
    cout<<"\nactual integral: "<<actual<<endl;
    float error =fabs((actual -ans)/actual *100);
    cout<<"\nerror: "<<error<<"%";
}
int main()
{
    float x0,xn,h,n;
    cout<<"enter the initial point: ";cin>>x0;
    cout<<"enter the final point: ";cin>>xn;
    cout<<"enter the no of sub-intervals: ";cin>>n;
    h=(xn-x0)/n;cout<<h<<endl;
    simpson8(x0,xn,h,n);return 0;
}