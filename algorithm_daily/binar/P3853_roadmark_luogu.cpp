#include<iostream>
using namespace std;

int L;//公路长度
int N;//原有路标数量
int K;//可添加路标数量
const int num=1e5;
int dis[num+1];

int check(int mid_dis)
{
    int count=0;
    for (int i=0;i<N-1;i++)
    {
        if((dis[i+1]-dis[i])>mid_dis)
        {
            count+=(dis[i+1]-dis[i])/mid_dis;
            if((dis[i+1]-dis[i])%mid_dis==0)
            {
                count--;
            }
        }
    }
    if(count<=K)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin>>L;
    cin>>N;
    cin>>K;
    for(int i=0;i<N;i++)
    {
        cin>>dis[i];
    }
    int left;
    int right;
    left=0;
    right=L;
    int mid_dis;
    int ans;
    while (left<=right)     //二分答案模板3（个人认为最好用的模板）但是一定要注意这里的等号
    {
        mid_dis=(left+right)/2;
        if (check(mid_dis))//满足条件 寻找可能的更小值
        {
            ans=mid_dis;
            right=mid_dis-1;
        }
        else
        {
            left=mid_dis+1;
        }
        
    }
    cout<<ans;
    return 0;
}
/*
做题总结
本题也属于二分答案的范畴，和跳石头那道题极为相似
但是在做题时有一个困境就是如何构造插入路标后的情况，起先一直想构造新的数组或者链表 但显然不行
做完两道题发现两道题的解法中都没有对最初的距离数组做改变
题目也并不需要知道插入路标/移走石头后具体的距离（因为用的是二分答案会和那个mid_dis作比较）
*/