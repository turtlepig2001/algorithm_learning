//
// Created by 86184 on 2021-06-23.
//
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class Queen{
    friend void nQueen();
    void Output(int *x,int n);

private:
    bool canPlace(int t);
    void backTrack(int t,long &sum);
    int n;//皇后个数
    int *x;//当前解
    long sum;//方案数
};

void nQueen(){
    Queen X;
    int n=0;
    cout<<"请输入给定的n"<<endl;
    cin>>n;
//    X.n=n;
    X.sum=0;
//    int *p=new int [n+1];
//    X.x=p;
    cout<<"计算开始-----------------------------------------"<<endl;
    cout<<"n后数"<<"         "<<"第一个解"<<"                      "<<"解数"<<endl;
    for (int i = 4; i <=n ; ++i) {
        X.n=i;
        X.x=new int [X.n+1];
        X.sum=0;
        cout<<i<<"         ";
        X.backTrack(1,X.sum);
        cout<<setw(25-i)<<setfill(' ')<<X.sum<<endl;
    }

    delete[] X.x;
}

void Queen::backTrack(int t,long &sum) {
    if (t>n)
    {
        sum++;
        if (sum==1)
        {
            Output(x,n);
        }
        return;
    }
    for (int i = 1; i <=n ; ++i) {
        x[t]=i;
        if (canPlace(t))
        {
            backTrack(t+1,sum);
        }
    }
}

bool Queen::canPlace(int t) {
    for (int i = 1; i < t; ++i) {
        if (x[t]==x[i]){
            return false;
        } else if (abs(t-i) == abs(x[t]-x[i]))
        {
            return false;
        }
    }
    return true;
}

void Queen::Output(int *x, int n) {
    cout<<"(";
    cout<<x[1];
    for (int i = 2; i <= n; ++i) {
        cout<<","<<x[i];
    }
    cout<<")";
}
int main()
{
    nQueen();
}