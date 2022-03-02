#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
// #include <cstdio>

using namespace std;

const int N=505;

vector<int> Graph[N];//邻接表
int indegree[N];//入度

int n,m;

vector<int> topologicalsort(int n)
{
    vector<int> topology;//拓扑排序序列
    priority_queue<int,vector<int>,greater<int>> node;
    for(int i=1;i<=n;i++)//注意这里的序号
    {
        if(indegree[i]==0)
        {
            node.push(i);
        }
    }
    while(!node.empty())
    {
        int u=node.top();
        node.pop();
        topology.push_back(u);
        for(int i=0;i<Graph[u].size();i++)
        {
            indegree[Graph[u][i]]--;
            if(indegree[Graph[u][i]]==0)
            {
                node.push(Graph[u][i]);
            }
        }
    }
    return topology;
}

int main()
{
    cin>>n>>m;
    memset(Graph, 0, sizeof(Graph));
    memset(indegree, 0, sizeof(indegree));
    for(int i=0;i<m;i++)
    {
        int from,to;
        cin>>from>>to;
        Graph[from].push_back(to);
        indegree[to]++;
    }
    vector<int>ans=topologicalsort(n);
    for(int i=0;i<ans.size();i++)
    {
        if(i==0)
        {
            cout<<ans[i];
        }
        else
        {
            cout<<" "<<ans[i];//题目要求最后一名后没有空格
        }
    }
    return 0;
}
