// secant method

#include<iostream>
#include<cmath>
using namespace std;

double fn(double x)
{
    //function is defined here.
    // return pow(x,3) - 3* pow(x,2) - x +3;
    // return sin(x) -3*x +2;
    return 2*pow(x,2) + 4*x -5;
}

double secant (float x1, float x2)
{
    double error = 0.0005;
    double x3 = ((x1*fn(x2) - x2*fn(x1))/(fn(x2)-fn(x1)));
    if(fabs((x1-x2)/x3)<= error)
    {
        return x3;
    }
    x1=x2;
    x2=x3;

    //recursive relation
    return secant(x1,x2);
}

int main()
{
    float x1,x2;
    cout<<"enter the initial guesses: "<<endl;
    cin>>x1>>x2;
    cout<<"the root of the equation is: "<< secant(x1,x2);
    return 0;
}

