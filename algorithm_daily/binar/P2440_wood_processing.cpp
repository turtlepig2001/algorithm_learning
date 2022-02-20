#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int N=100010;
const int INF=INT_MAX;

int n,k;
// int l=0;

int logs[N];

bool check(int mid)
{
    int x=0;
    for(int i=1;i<=n; i++)
    {
        x+=logs[i]/mid;
    }
    if(x>=k)
    {
        return true;
    }
    return false;
}

bool bless(int x, int y)
{
    return x>y;
}

int main()
{
    cin>>n>>k;
    int min_l=INF;
    int max_l=0;
    for(int i=1;i<=n; i++)
    {
        cin>>logs[i];
        min_l=min(logs[i],min_l);
        max_l=max(logs[i],max_l);
    }
    int left=1;
    int right=max_l;
    long long ans=0;
    int mid;
    sort(logs+1,logs+n+1,bless);//需要注意这道题允许剩余木材（包括完全不砍）所有要使用一下贪心法
    while(left <= right)
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