#include<iostream>
using namespace std;

/*
二分答案模板1
    int l=1,r=ll;// 1 是答案的最小值，ll是答案的最大值
    while(l<=r)
    {
        int mid=(l+r)>>1,q=check(mid);//“>>1”相当于“/2”  >>是一个移位运算
        if(q>m)r=mid-1;
        else l=mid+1;
    }
模板2
    while (l < r)
    {
        int mid = l + r + 1 >> 1;	//(l+r+1)/2
        if (check(mid))  l = mid;
        else r = mid - 1;
    }

比较好用的模板
int l,r,mid,ans;
while(l<=r)
{
    mid=(l+r)/2;
    if(check(mid))l=mid+1,ans=mid;
    else r=mid-1;  
}

*/
// const int L=1e9;
int dis[50010];


int check(int mid_dis,int n,int m)
{
    int count=0;//统计取出的石头个数
    int now=0;//当前的石头位置
    // for(int i=0;i<=n;i++)
    // {
    //     i++;
    //     if((dis[i]-dis[now])<mid_dis)//mid_dis不是最小距离,抽走当前这个石头
    //     {
    //         count++;
    //     }
    //     else
    //     {
    //         now=i;
    //     }
    // }
    int i=0;
    while(i<n+1)
    {
        i++;
        if((dis[i]-dis[now])<mid_dis)
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
    long long left=1;
    long long right=L;
    if(n==0)
    {
        cout<<L;
        return 0;
    }
    while(left<right)
    {
        int mid=left+right+1>>1;//为什么+1？+2测试也通过
        if(check(mid,n,m))
        {
            left=mid;
        }
        else
        {
            right=mid-1;
        }
    }
    cout<<left;
    return 0;
}

/*
两个问题：
1.check函数的循环问题：for循环中有i++ 在循环体里又写了i++ 采取原先下一跳的方法可以解决
2.取中值加一的问题：如果left和right的差为1 会死循环
*/
//洛谷P2678_跳石头问题_二分答案 