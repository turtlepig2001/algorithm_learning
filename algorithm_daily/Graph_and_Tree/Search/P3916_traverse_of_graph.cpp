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


int DFS(int from,int &ans)
{
    for(int i=0;i<Graph[from].size();i++)
    {
        if(vis[Graph[from][i]])
        {
            continue;
        }
        vis[Graph[from][i]]=true;
        if(ans<Graph[from][i])
        {
            ans=Graph[from][i];
        }
        DFS(Graph[from][i],ans);
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int from,to;
        cin>>from>>to;
        Graph[from].push_back(to);
    }
    for(int i=1;i<=n;i++)
    {
        memset(vis, false, sizeof(vis));
        ans[i] = i;
        vis[i] = true;
        ans[i]=DFS(i,ans[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}


