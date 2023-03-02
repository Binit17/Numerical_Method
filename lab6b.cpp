//solve 2nd order differential equation using rk4 method
//EULER, RK2 AND RK4 METHOD

#include<iostream>
using namespace std;

float fn(float x, float y,float z)
{
    return z;
}
float gn(float x, float y, float z)
{
    return 1+2*x*y-x*x*z;
}

float rk4(float x, float y, float z,float h,float xn)
{
    if(x>xn)
        return 0;
    cout<<x<<"\t"<<y<<"\t"<<z<<endl;
    float k1,k2,k3,k4,k,l1,l2,l3,l4,l;
    k1=h*fn(x,y,z);
    l1=h*gn(x,y,z);
    k2=h*fn(x+h*0.5,y+k1*0.5,z+l1*0.5);
    l2=h*gn(x+h*0.5,y+k1*0.5,z+l1*0.5);
    k3=h*fn(x+h*0.5,y+k2*0.5,z+l2*0.5);
    l3=h*gn(x+h*0.5,y+k2*0.5,z+l2*0.5);
    k4=h*fn(x+h,y+k3,z+l3);
    l4=h*gn(x+h,y+k3,z+l3);
    k=(k1+2*k2+2*k3+k4)/6;
    l=(l1+2*l2+2*l3+l4)/6;
    y=y+k;
    x=x+h;
    z=z+l;
    return rk4(x,y,z,h,xn);
}

int main()
{
    float x,y,z,xn,h;
    cout<<"enter initial values: x0,y0,z0,h,xn: ";
    cin>>x>>y>>z>>h>>xn;
    // float n= (xn-x)/h +1;
    cout<<"RK4 METHOD"<<endl;
    rk4(x,y,z,h,xn);
    return 0;
}