#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>


using namespace std;
const int num_of_nodes=1010;
const int num_of_edges=100010;
const int INF=INT_MAX;
/*
使用一个二维数组存储个点之间的最短距离，就像是邻接矩阵
求最短距离还是使用邻接表
*/
int n;
int m;




struct edge 
{
    int to;//destination
    int time;
    edge(int to, int time):to(to),time(time) {}
};
struct node
{
    int number;
    int cost_time;//某点到此所需的时间
    node(int number, int cost_time):number(number),cost_time(cost_time){}
    bool operator<(const node& other) const
    {
        return cost_time>other.cost_time;
    }
};

vector<edge> Graph[num_of_nodes];
vector<edge> Graph2[num_of_nodes];
priority_queue<node> mypriority_queue;

int costs1[num_of_nodes];//记录最短距离
int costs2[num_of_nodes];

void Dijkstra1()
{
    costs1[1] = 0;
    mypriority_queue.push(node(1,costs1[1]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            int t=Graph[u][i].to;
            int v=Graph[u][i].time;
            if(costs1[t]>(costs1[u]+v))
            {
                costs1[t]=costs1[u]+v;
                mypriority_queue.push(node(t,costs1[t]));
            }
        }
    }
    return;
}

void Dijkstra2()
{
    costs2[1] = 0;
    mypriority_queue.push(node(1,costs2[1]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        for(int i=0;i<Graph2[u].size();i++)
        {
            int t=Graph2[u][i].to;
            int v=Graph2[u][i].time;
            if(costs2[t]>(costs2[u]+v))
            {
                costs2[t]=costs2[u]+v;
                mypriority_queue.push(node(t,costs2[t]));
            }
        }
    }
    return;
}

int main()
{
    cin>>n>>m;
    memset(Graph, 0, sizeof(Graph));
    memset(Graph2, 0, sizeof(Graph2));
    for (int i =1;i<=m;i++)
    {
        int from,to,timecost;
        cin>>from>>to>>timecost;
        Graph[from].push_back(edge(to,timecost));//单向道路 有向图 
        Graph2[to].push_back(edge(from,timecost));//建一张反向图
    }
    //正着跑一遍
    {
        fill(costs1+1,costs1+1+n,INF);
        Dijkstra1();
    }
    //反着跑一遍
    {
        fill(costs2+1,costs2+1+n,INF);
        Dijkstra2();
    }
    int sum = 0;
    for(int i =1;i<=n;i++)
    {
        sum+=costs1[i];
        sum+=costs2[i];
    }
    cout<<sum;
    return 0;
}