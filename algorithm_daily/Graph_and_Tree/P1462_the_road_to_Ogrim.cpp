#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
#include<climits>

using namespace std;

int n;//number of city
int m;//number of road
int b;//blood

const int max_num_of_node=1e4;
const int INF=INT_MAX;//无穷

int c[max_num_of_node+1];//原点到各点的最小金钱代价
int c_hp[max_num_of_node+1];//原点到各点的最小代价（血量，即相当于距离）

struct edge
{
    int to;//next position
    int cost_hp;//走这条路消耗的血量
    edge(int t,int l):to(t),cost_hp(l){}
};

struct node
{
    int number;//编号
    // int cost;//经过此处需要花费的金钱
    int cost_blood;//原点到该点消耗的血量
    node(int n,int d):number(n),cost_blood(d){}
    bool operator<(const node& n) const //一定要加const
    {
        return cost_blood>n.cost_blood;// 优先队列是默认最大值放前面
    }
};


vector<edge> Graph[max_num_of_node+1]; //向量实现邻接表 实现图
priority_queue<node> mypriority_queue;//



int check(int mid)//二分的是金钱   还需要注意起始点和终点也要收费
{
    if(mid<c[1])
    {
        return 0;
    }
    c_hp[1]=0;
    // int temp_hp=b;//剩余血量
    mypriority_queue.push(node(1,c_hp[1]));
    while(!mypriority_queue.empty())
    {
        int u=mypriority_queue.top().number;
        mypriority_queue.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            int t=Graph[u][i].to;
            int d=Graph[u][i].cost_hp;
            if((c_hp[t]>=c_hp[u]+d)&&c[t]<=mid)//消耗的金钱数小于等于限制可以选择这个节点
            {
                c_hp[t]=c_hp[u]+d;
                mypriority_queue.push(node(t,c_hp[t]));
            }
        }
    }
    if(c_hp[n]>=0&&c_hp[n]<=b)
    {
        return 1;
    }
    return 0;

}


int main()
{
    cin>>n;
    cin>>m;
    cin>>b;
    int min=INF,max=0;
    for (int i = 1; i <= n; i++)
    {
        cin>>c[i];
        if(c[i]<min) min=c[i];
        if(c[i]>max) max=c[i];
    }
    memset(Graph, 0,sizeof(Graph));//图初始化
    fill(c_hp+1,c_hp+n+1,INF);//距离初始化为无穷
    for(int i=1;i<=m;i++)
    {
        int from,to,cost_hp;
        cin>>from>>to>>cost_hp;
        Graph[from].push_back(edge(to,cost_hp));
        Graph[to].push_back(edge(from,cost_hp));//无向图 需要双向赋值
    }
    int left=min;
    int right=max;
    int ans=0;
    while(left <= right)
    {
        int mid=(left+right)/2;
        if(check(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    if(ans!=0)
    {
        cout<<ans;
    }
    cout<<"AFK";
    return 0;
}   




