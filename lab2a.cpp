// curve fitting using least square method.
//st.line 
#include<iostream>
#include<cmath>
using namespace std;

float determinant(float a, float b, float c, float d)
{
    return ((a*d)-(b*c));
}

void generateStline(float *x, float *y, int n)
{
    float sum1,sum2,sum3,sum4;
    sum1=sum2=sum3=sum4=0;
    for(int i=0;i<n;i++)
    {
        sum1=sum1+x[i];
        sum2=sum2+ y[i];
        sum3=sum3+ x[i]*y[i];
        sum4=sum4+ x[i]*x[i];
    }
    float a= float(determinant(sum2,sum1,sum3,sum4)/determinant(n,sum1,sum1,sum4));
    float b= float(determinant(n,sum2,sum1,sum3)/determinant(n,sum1,sum1,sum4));
    cout<<"required eq is: "<<endl;
    cout<<" y ="<<a <<" + "<<b<<"x"<<endl;
}

int main()
{
    float x[]={1,-2,3,4,5};
    float y[]={3,4,5,-6,8};
    generateStline(x,y,5);
    return 0;
}