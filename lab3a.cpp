// newton raphson method.

#include<iostream>
#include<cmath>
using namespace std;

double fn1(double x)
{
    //function is defined here.
    // return sin(x) - 3*x +2;
    // return 2*pow(x,2) + 4*x -5;
    // return pow(x,3) - 3* pow(x,2) - x +3;
    return 3*x - exp(-x) -2;

}
double fn2(double x)
{
    if((cos(x) - 3)==0)
    {
        cout<<"this point is not feasible, try another point."<<endl;
        return 0;
    }
    //derivative of function is defined here.
    // return cos(x) - 3;
    return 4*x + 4;
}

double solution(double x0, int count)
{
    //base case
    if(count <= 0)
    {
        cout<<"Cannot be solved by Newton Raphson"<<endl;
        return 0;
    }
    double x1 = (x0 - (fn1(x0)/fn2(x0)));
    if (fabs(x1-x0) <= 0.0001 )
    {
        cout<<"the root of the equation is : "<< x1<<endl;
        return 1;
    }

    return solution(x1,count-1);
}

int main()
{
    double initial;
    cout<<"enter the initial point: "<<endl;
    cin>>initial;
    solution(initial,50);
    // here count is for no. of iterations i.e to solve the oscillation problem.
    return 0;
}
