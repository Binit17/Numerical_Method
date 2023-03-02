// bisection method

#include<iostream>
#include<cmath>

using namespace std;

#define function "x.sinx + cosx"

double fn(double x)
{
    return x*sin(x)+ cos(x);
    // return x*sin(x)+cos(x);
    // return x + sin(x);
}

struct endValues
{
    float a;   
    float b;
}e;



double findSolution(float a, float b,int n)
{
    if (n<=0)
    {
        // cout<<"the curve might be discontinuos."<<endl;
        cout<<"the optimal solution is : "<<(a+b)/2;
        return 0;
    }
    
    else
    {
        if (fn(a)*fn(b)>0)
    {
        cout<<"there is no solution in this interval.";
        return 0;
    }

    double c = double((a+b)/2);

    cout<<a<<"\t\t\t"<<b<<"\t\t\t"<<c<<"\t\t\t"<<fn(a)<<"\t\t\t"<<fn(b)<<"\t\t\t"<<fn(c)<<endl;

    if (fabs(fn(c))<=0.0005)  //we use fabs() to find the absolute value of a floating/double value.
    {
        cout<<"the optimal solution is : "<<c<<endl;
        return 1;
    }
    
    if (fn(a)*fn(c)<0)
        return findSolution(a,c,n-1);
    else
        return findSolution(c,b,n-1);
    }
    
}

int main()
{
    e.a=2;
    e.b=3;

    int n=int((fabs(log10(e.b-e.a))-log10(0.0005))/log10(2));

    cout<<"Function is: "<<function<<endl<<endl;

    cout<<"max no. of iterations for given interval: "<<n<<endl<<endl;

    cout<<"x1\t\t\tx2\t\t\tx0\t\t\tf(x1)\t\t\t\tf(x2)\t\t\tf(x0)"<<endl<<endl;
    findSolution(e.a,e.b,n);
    return 0;
}