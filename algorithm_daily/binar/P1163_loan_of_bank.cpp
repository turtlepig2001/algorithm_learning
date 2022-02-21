#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double loan;
double pm;
double month;

double check(double mid)
{
    double x=loan;
    for (int i=1;i<=month;i++)
    {
        x=x*(1+mid)-pm;
    }
    return x;
}

int main()
{
    cin>>loan>>pm>>month;
    double left= 0.0;
    double right=5.0;
    double mid;
    double ans;
    while (right-left>0.0001)
    {
        mid=(left+right)/2;
        if(check(mid)>0.0001)
        {
            right=mid;
        }
        else
        {
            left=mid;
        }
    }
    cout<<fixed<<setprecision(1)<<left*100;
    return 0;
}

//假设利率按月累计