//深度优先搜索版拓扑排序
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

const int N=10010;

int n;
int times[N];//一定不要使用time作为数组名 应该是一个关键词
int premise[N];
int indegree[N];
int anstime[N];//这里的意思和原来的拓扑排序版本正好相反 是指从该事件出发到整个过程结束所消耗的时间

vector<int> Graph[N];

int DFS(int from)
{
    if(anstime[from])
    {
        return anstime[from];
    }
    for(int i=0;i<Graph[from].size();i++)
    {
        anstime[from]=max(anstime[from],DFS(Graph[from][i]));
    }
    anstime[from]+=times[from];
    return anstime[from];
}

int main()
{
    cin>>n;
    memset(indegree, 0, sizeof(indegree));
    memset(Graph, 0, sizeof(Graph));
    memset(anstime, 0, sizeof(anstime));
    memset(times, 0, sizeof(times));
    for(int i=1;i<=n;i++)
    {
        int from;
        // cin>>from>>len;
        // time[from]=len;
        cin>>from>>times[i];
        int temp;
        cin>>temp;
        while(temp!=0)
        {
            Graph[temp].push_back(from);
            indegree[from]++;
            cin>>temp;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,DFS(i));
    }
    cout<<ans;
    return 0;
}