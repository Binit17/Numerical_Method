#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<float> matrixMul(float a[10][10], vector<float> b)
{
    vector<float> mul;
    int n = b.size();
    for (int i = 0; i < n; i++)
    {
        float sum=0;
        for (int k = 0; k < n; k++)
        {
            sum+=a[i][k]*b.at(k);
        }
        mul.push_back(sum);
    }
    return mul;
}
void findEigen(float a[10][10],vector<float> vect)
{
    vector<float> temp = vect;
    float temphighest, highest;
    int n = vect.size();
    temphighest = *max_element(temp.begin(),temp.end());
    for (int i = 0; i < n; i++)
    {
        vect.at(i)=vect.at(i)/temphighest;
    } 
    vect=matrixMul(a,vect);
    highest = *max_element(vect.begin(), vect.end());
    if(fabs(temphighest-highest)<=0.0005)
    {
        cout<<"\neigen value: "<<highest<<endl;
        cout<<"eigen vector: \n";
        for (int i = 0; i < n; i++)
        {
            cout<<vect.at(i)/highest<<endl;
        } 
        return;
    }
    findEigen(a,vect);
}

int main()
{
    float mat[10][10];
    vector<float> guess;
    vector<float> ans;
    int n;cout<<"enter the order of matrix: ";cin>>n;
    cout<<"enter the elements of matrix: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<"mat["<<i<<"]["<<j<<"]: ";
            cin>>mat[i][j];
        }
    }
    cout<<"enter the initial guess vector: \n";
    for (int i = 0; i < n; i++)
    {
        int value;cin>>value;
        guess.push_back(value);
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    ans=matrixMul(mat,guess);
    findEigen(mat,ans);
    return 0;
}