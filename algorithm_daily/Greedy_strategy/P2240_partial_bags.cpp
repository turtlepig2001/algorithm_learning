#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

//部分背包问题 将金币按照重量价值比排序依次从最大的开始装入背包

int N;//number of coin
float T;//capacity of bag
float values=0;

struct coin
{
    float m;//height
    float v;//value
    float p;//比例
    coin():m(0), v(0), p(0){}//initial
};

bool bgreater(coin& a,coin& b)
{
    return (a.v/a.m) > (b.v/b.m);
}

int main()
{
    cin >> N >> T;
    coin *coins=new coin[N];
    for (int i=0;i<N; i++)
    {
        cin>>coins[i].m;
        cin>>coins[i].v;
    }
    sort(coins,coins+N,bgreater);
    for (int i=0;i<N;i++)
    {
        if (T==0)//已经装满了
        {
            /* code */
            break;
        }
        else
        {
            coins[i].p=(float)T/(float)coins[i].m;
            if(coins[i].p>1)
            {
                coins[i].p=1;
            }
            T-=coins[i].p*(float)coins[i].m;
            values+=coins[i].p*(float)coins[i].v;
        }
    }
    cout<<fixed<<setprecision(2)<<values<<endl;
    return 0;

}