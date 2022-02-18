/*
二分答案模板
int l,r,mid,ans;
while(l<=r)
{
    mid=(l+r)/2;
    if(check(mid))l=mid+1,ans=mid;
    else r=mid-1;  
}
*/

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int N = 1000010;
const int INF=INT_MAX;

int n;
int m;
long long sum = 0;
int trees[N];

bool bgreater(int x, int y)
{
    return x<y;
}

bool check(int mid)
{
    sum=0;
    for(int i=1; i<=n;i++)
    {
        if(trees[i]>mid)
        {
            sum+=(trees[i]-mid);
        }
    }
    if(sum>=m)
    {
        return true;
    }
    return false;
}

int main()
{
    cin >> n>>m;
    int min_ =0;
    int max_ =0;
    for(int i=1;i<=n; i++)
    {
        cin>>trees[i];
        min_=min(min_, trees[i]);
        max_=max(max_, trees[i]);
    }
    sort(trees+1,trees+n+1,bgreater);
    int left=min_, right=max_;
    int mid;
    int ans;
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