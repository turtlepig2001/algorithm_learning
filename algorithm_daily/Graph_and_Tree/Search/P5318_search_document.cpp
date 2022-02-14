#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=100005;
const int M=1000005;

int n,m;
int vis[N];

vector<int>Graph[N];
queue<int> q_DFS; 
queue<int> q_BFS;
queue<int> q_BFS_;

void DFS(int from)
{
    q_DFS.push(from);
    vis[from] = true;
    for(int i=0;i<Graph[from].size();i++)
    {
        if(vis[Graph[from][i]])
        {
            continue;
        }
        DFS(Graph[from][i]);
    }
}

void BFS(int from)
{
    q_BFS.push(from);
    q_BFS_.push(from);
    vis[from] = true;
    while(!q_BFS.empty())
    {
        int k=q_BFS.front();
        q_BFS.pop();
        for(int i=0;i<Graph[k].size();i++)
        {
            if(!vis[Graph[k][i]])
            {
                q_BFS.push(Graph[k][i]);
                q_BFS_.push(Graph[k][i]);
                vis[Graph[k][i]] = true;
            }
        }
    }
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
        sort(Graph[i].begin(),Graph[i].end());
    }
    memset(vis, false, sizeof(vis));
    DFS(1);
    while(!q_DFS.empty())
    {
        cout<<q_DFS.front()<<" ";
        q_DFS.pop();
    }
    cout<<endl;
    memset(vis, false, sizeof(vis));
    BFS(1);
    while(!q_BFS_.empty())
    {
        cout<<q_BFS_.front()<<" ";
        q_BFS_.pop();
    }
    return 0;
}