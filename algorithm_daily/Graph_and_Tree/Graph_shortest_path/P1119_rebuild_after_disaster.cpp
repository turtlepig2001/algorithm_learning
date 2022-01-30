#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>


using namespace std;

const int num_of_nodes=200;
const int num_of_edges=200*199/2;
const int INF=INT_MAX;

int n,m;//num_of_nodes num_of_roads
int q;
int rebuild_time[num_of_nodes];
int dis[num_of_nodes][num_of_nodes];
int vis[num_of_nodes][num_of_nodes];

int lasttime=0;
int nowtime=0;

struct edge
{
    int to;
    int length;
    edge(int to, int length):to(to),length(length){}
};

struct node
{
    int number;
    int cost;
    node(int number, int cost):number(number),cost(cost){}
    bool operator<(const node& other) const 
    {
        return number > other.number;
    }
};

vector<edge> Graph[num_of_nodes];
priority_queue<node>mypriority_queue;

void check(int s, int t)
{
    fill(dis[s],dis[s]+n,INF);
    dis[s][s]=0;
    mypriority_queue.push(node(s,dis[s][s]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        if(nowtime<rebuild_time[u])//u还未重建
            continue;
        vis[s][u]=true;
        for(int i=0;i<Graph[u].size();i++)
        {
            int t=Graph[u][i].to;
            if(nowtime<rebuild_time[t])
            {
                continue;
            }
            int v=Graph[u][i].length;
            if(dis[s][t]>dis[s][u]+v)
            {
                dis[s][t]=dis[s][u]+v;
                mypriority_queue.push(node(t,dis[s][t]));
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>rebuild_time[i];
    }
    memset(Graph, 0, sizeof(Graph));
    for(int i=0;i<m;i++)
    {
        int from,to,length;
        cin>>from>>to>>length;
        Graph[from].push_back(edge(to,length));
        Graph[to].push_back(edge(from,length));
    }

    cin>>q;
    int ans[q];
    for(int i=0;i<q;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        lasttime=nowtime;
        nowtime=t;
        if(rebuild_time[x]>t||rebuild_time[y]>t)//未重建完成不可达
        {
            ans[i]=-1;
        }
        else
        {
            check(x,t);
            if(dis[x][y]==INF)
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=dis[x][y];
            }
        }

    }
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}