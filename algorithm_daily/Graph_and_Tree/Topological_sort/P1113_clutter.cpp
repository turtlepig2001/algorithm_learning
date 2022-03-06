#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int N=10010;

int n;
int times[N];//一定不要使用time作为数组名 应该是一个关键词
int premise[N];
int indegree[N];
int anstime[N];

vector <int>Graph[N];

void topologicalsort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            anstime[i]=times[i];//这一步很重要 最先做的事情也是有完成时间的
        }
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<Graph[u].size();i++)
        {
            int v=Graph[u][i];
            indegree[v]--;
            anstime[v]=max(anstime[v],anstime[u]+times[v]);
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
    }
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
    topologicalsort();
    int maxt=anstime[1];
    for(int i=2;i<=n;i++)
    {
        maxt=max(maxt,anstime[i]);
    }
    cout<<maxt;
    return 0;
}

/*
题目背景
John的农场在给奶牛挤奶前有很多杂务要完成，每一项杂务都需要一定的时间来完成它。比如：他们要将奶牛集合起来，将他们赶进牛棚，为奶牛清洗乳房以及一些其它工作。尽早将所有杂务完成是必要的，因为这样才有更多时间挤出更多的牛奶。当然，有些杂务必须在另一些杂务完成的情况下才能进行。比如：只有将奶牛赶进牛棚才能开始为它清洗乳房，还有在未给奶牛清洗乳房之前不能挤奶。我们把这些工作称为完成本项工作的准备工作。至少有一项杂务不要求有准备工作，这个可以最早着手完成的工作，标记为杂务11。John有需要完成的nn个杂务的清单，并且这份清单是有一定顺序的，杂务k(k>1)k(k>1)的准备工作只可能在杂务11至k-1k−1中。
写一个程序从11到nn读入每个杂务的工作说明。计算出所有杂务都被完成的最短时间。当然互相没有关系的杂务可以同时工作，并且，你可以假定John的农场有足够多的工人来同时完成任意多项任务。
*/