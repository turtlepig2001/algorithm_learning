#include <iostream>
#include <algorithm>

using namespace std;

//从小到大排序 顺序取判断差值是否为一和是否相等 二分查找最小值的最大值

const int N=100010;
int n;
long long power[N];

int group_num;

bool cmp(int a, int b)
{
    return a<b;
}

bool check(int mid)
{
    group_num = N;
    int temp_num=1;
    bool ck=true;
    for(int i=1; i<n; i++)
    {
        if(power[i+1]!=power[i]&&(power[i+1]-power[i])==1)
        {
            temp_num++;//添加下一个元素
            ck=true;
        }
        else//一组已经分完了
        {
            if(group_num>temp_num)
            {
                group_num = temp_num;
            }
            ck=false;
            // temp_num = 1;//重新计数
        }
        if(!ck)
        {
            temp_num=1;
        }
    }
    if(group_num>temp_num)
    {
        group_num = temp_num;//特殊判断最后一组
    }
    return group_num>=mid;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>power[i];
    }
    sort(power+1,power+n+1,cmp);
    int left=1;
    int right=n;
    int ans;
    int mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(check(mid))
        {
            left=mid+1;
            ans=mid;
        }
        else
        {
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}

//忽略的一种情况 111 222 333 444，如果出现这种数据最小组数一定是1，但显然不是这种分组方式