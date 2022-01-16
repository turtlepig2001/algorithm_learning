#include<iostream>
using namespace std;

/*
二分答案模板
    int l=1,r=ll;// 1 是答案的最小值，ll是答案的最大值
    while(l<=r)
    {
        int mid=(l+r)>>1,q=check(mid);//“>>1”相当于“/2”  >>是一个移位运算
        if(q>m)r=mid-1;
        else l=mid+1;
    }
*/
// const int L=1e9;
int dis[50001];


int check(int mid_dis,int n,int m)
{
    int count=0;//统计取出的石头个数
    int now=0;//当前的石头位置
    for(int i=0;i<=n;i++)
    {
        i++;
        if((dis[i]-dis[now])<mid_dis)//mid_dis不是最小距离,抽走当前这个石头
        {
            count++;
        }
        else
        {
            now=i;
        }
    }
    if(count<=m)
    {
        return 1;//满足情况
    }
    return 0;

}

int main()
{
    int m,n,L;
    cin>>L>>n>>m;
    dis[0]=0;
    dis[n+1]=L;
    for(int i=1;i<=n;i++)
    {
        cin>>dis[i];
    }
    //二分查找一个距离mid_dis,将其与石头中的最小间距作比较
    int left=1;
    int right=L;
    while(left<right)
    {
        int mid=(left+right)>>1;
        if(check(mid,n,m))
        {
            left=mid;
        }
        else
        {
            right=mid;
        }
    }
}