#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

const int num_of_nodes=100000;
const int num_of_edges=200010;
const int INF=INT_MAX;

int n,m,s;

struct edge
{
    int to;
    int length;
    edge(int x, int y):to(x),length(y) {}
};

struct node
{
    int number;
    int cost;
    node(int number, int cost):number(number),cost(cost) {}
    bool operator<(const node& other) const 
    {
        return cost > other.cost;
    }
};

vector<edge> Graph[num_of_edges];
priority_queue<node> mypriority_queue;
int dis[num_of_nodes];
int vis[num_of_nodes];//记得做vis优化

void dijkstra(int s)
{
    dis[s]=0;
    mypriority_queue.push(node(s,dis[s]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        if(vis[u])
            continue;
        vis[u] = true;
        for(int i=0;i<Graph[u].size();i++)
        {
            int t=Graph[u][i].to;
            int v=Graph[u][i].length;
            if(dis[t]>dis[u]+v)
            {
                dis[t]=dis[u]+v;
                mypriority_queue.push(node(t,dis[t]));
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m>>s;

    memset(Graph, 0, sizeof(Graph));//cstring
    fill(dis+1,dis+n+1,INF);
    fill(vis+1,vis+n+1,false);

    for(int i=0;i<m;i++)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        Graph[from].push_back(edge(to,cost));//有向图
    }

    dijkstra(s);

    for(int i=1;i<=n;i++)
    {
        cout<<dis[i]<<" ";
    }
    return 0;

}