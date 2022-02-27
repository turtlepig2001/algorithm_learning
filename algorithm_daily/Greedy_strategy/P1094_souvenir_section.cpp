#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N=30010;

int w;
int n;
int souvs[N];
bool vis[N];

bool cmp(const int &a, const int &b)
{
    return a < b;
}

int main()
{
    cin>>w>>n;
    for (int i = 1; i <=n; i++)
    {
        cin>>souvs[i];//两个指针指向同一点就只剩下了一个物品必须单独列一组同时循环结束或者是指针改变
    }
    sort(souvs+1,souvs+1+n,cmp);
    int left=1;
    int right=n;
    memset(vis, false, sizeof(vis));
    int ans=0;
    while(left <= right)
    {
        if(left == right)
        {
            ans+=1;
            break;
        }
        if(souvs[left]+souvs[right]<=w)
        {
            ans+=1;
            left+=1;
            right-=1;
        }
        else
        {
            right-=1;
            ans+=1;
        }
    }
    cout<<ans;
}