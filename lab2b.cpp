// curve fitting using least square method.
//exponential curve
#include<iostream>
#include<cmath>
using namespace std;

float determinant(float a, float b, float c, float d)
{
    return ((a*d)-(b*c));
}

void generateExpCurve(float *x, float *y, int n)
{
    float sum1,sum2,sum3,sum4;
    sum1=sum2=sum3=sum4=0;
    for(int i=0;i<n;i++)
    {
        sum1=sum1+x[i];
        sum2=sum2+ log(y[i]);
        sum3=sum3+ x[i]*log(y[i]);
        sum4=sum4+ x[i]*x[i];
    }
    float A= float(determinant(sum2,sum1,sum3,sum4)/determinant(n,sum1,sum1,sum4));
    float b= float(determinant(n,sum2,sum1,sum3)/determinant(n,sum1,sum1,sum4));
    float a=exp(A);
    cout<<"required eq is: "<<endl;
    cout<<" y ="<<a <<"e^"<<b<<"x"<<endl;
}

int main()
{
    float y[]={1,-2,3,4,5};
    float x[]={3,4,5,6,8};
    generateExpCurve(x,y,5);
    return 0;
}