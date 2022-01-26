#include <iostream>
using namespace std;

int n;//盒子个数
int x;//限制系数
long long sum = 0;//数据比较大这里一定要改成long long

int main()
{
    cin>>n;
    cin>>x;
    int cases[n];
    for(int i=0; i <n; i++)
    {
        cin>>cases[i];
    }
    int diff = 0;//差
    for(int i=1; i <n; i++)
    {
        if((cases[i]+cases[i-1])>x)
        {
            diff = cases[i]+cases[i-1]-x;//需要减去的总和
            if(cases[i]>=diff)
            {
                // cases[i] = cases[i]-(cases[i]+cases[i-1]-x);
                cases[i]=cases[i]-diff;
            }
            else
            {
                cases[i-1]=cases[i-1]-(diff-cases[i]);
                cases[i]=0; 
            }
            sum+=diff;
        }
    }
    cout<<sum;
    return 0;
}
/*
解题总结：
这道题主要是以贪心为主+加上一个模拟的过程，不看题解已经很接近想到了
除了第一个数以外其余都是与两个分组有关系
从第一个数开始一组之和超过x后要尽可能先吃后面的盒子因为会同时影响两个
吃完之后后面的这个盒子就一定不会超过限制，后面的过程以此类推
*/
