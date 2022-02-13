#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

const int nm=1e5;

int n,m;
int ans[nm];
int vis[nm];

vector <int>Graph[nm];

//这次采用反向建图的方式


void DFS(int from,int an)
{
    if(ans[from])//这个点更新过值的话与他联通的以他为最大值也更新过  因为这里是递归调用 深度优先搜索
    {
        return;
    }
    ans[from]=an;
    for(int i=0;i<Graph[from].size();i++)
    {
        DFS(Graph[from][i],an);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int from,to;
        cin>>from>>to;
        Graph[to].push_back(from);
    }
    memset(ans,0,sizeof(ans));
    for(int i=n;i>=1;i--)
    {
        DFS(i,i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}


