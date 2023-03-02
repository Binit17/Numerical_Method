//EULER, RK2 AND RK4 METHOD

#include<iostream>
using namespace std;

float fn(float x, float y)
{
    return (2*y)/x;
}
float euler(float x, float y, float h,float n)
{
    if(n<=0)
        return 0;
    cout<<x<<"\t"<<y<<endl;
    y=y+h*fn(x,y);
    x=x+h;
    return euler(x,y,h,n-1);
}
float rk2(float x, float y, float h,float n)
{
    if(n<=0)
        return 0;
    cout<<x<<"\t"<<y<<endl;
    float k1,k2,k;
    k1=h*fn(x,y);
    k2=h*fn(x+h,y+k1);
    k=0.5*(k1+k2);
    y=y+k;
    x=x+h;
    return rk2(x,y,h,n-1);
}
float rk4(float x, float y, float h,float n)
{
    if(n<=0)
        return 0;
    cout<<x<<"\t"<<y<<endl;
    float k1,k2,k3,k4,k;
    k1=h*fn(x,y);
    k2=h*fn(x+h*0.5,y+k1*0.5);
    k3=h*fn(x+h*0.5,y+k2*0.5);
    k4=h*fn(x+h,y+k3);
    k=(k1+2*k2+2*k3+k4)/6;
    y=y+k;
    x=x+h;
    return rk4(x,y,h,n-1);
}

int main()
{
    float x,y,xn,h;
    cout<<"enter initial values: x0,y0,h,xn: ";
    cin>>x>>y>>h>>xn;
    float n= (xn-x)/h +1;
    cout<<"EULER METHOD"<<endl;
    euler(x,y,h,n);
    cout<<"RK2 METHOD"<<endl;
    rk2(x,y,h,n);
    cout<<"RK4 METHOD"<<endl;
    rk4(x,y,h,n);
    return 0;
}