#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

const int num_of_nodes=1000010;
const int num_of_edges=4000010;//双向边
const int INF=INT_MAX;
// int en[num_of_nodes][num_of_nodes]={0};
// int nums[num_of_nodes][num_of_nodes]={0};
const int mod=100003;


int n,m;

int dis[num_of_nodes];
int num[num_of_nodes]={0};
int vis[num_of_nodes];

struct edge
{
    int to;
    int dis;
    edge():to(0),dis(0){}
    edge(int to, int dis):to(to),dis(dis){}
};

struct node
{
    int number;
    int cost;
    node(int number, int cost):number(number),cost(cost){}
    bool operator<(const node& other) const
    {
        return cost > other.cost;
    }
};

vector<edge> Graph[num_of_nodes];
priority_queue<node> mypriority_queue;

void dijkstra()
{
    dis[1]=0;
    mypriority_queue.push(node(1,dis[1]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        if(vis[u])
            continue;
        vis[u]=true;
        for(int i=0;i<Graph[u].size();i++)
        {
            int t=Graph[u][i].to;
            // int v=Graph[u][i].dis;
            if(dis[t]>dis[u]+1)
            {
                dis[t]=dis[u]+1;
                num[t]=num[u];   //这里为什么不需要num%mod？ 新点的值用旧值覆盖
                mypriority_queue.push(node(t,dis[t]));
            }
            else if(dis[t]==(dis[u]+1))
            {
                num[t]=num[u]+num[t];   //100003+1 
                num[t]=num[t]%mod;
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    memset(Graph, 0, sizeof(Graph));
    fill(dis+1,dis+1+n,INF);
    for(int i=1;i<=m;i++)
    {
        int from,to;
        cin>>from>>to;
        Graph[from].push_back(edge(to,1));
        Graph[to].push_back(edge(from,1));
    }
    num[1] = 1;
    fill(vis+1,vis+1+n,false);
    dijkstra();
    for(int i=1;i<=n;i++)
    {
        cout<<num[i]<<endl;//最后加mod会wa一个点
    }
    return 0;
}