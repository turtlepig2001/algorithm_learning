#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int k,n,m;

const int K=110;
const int N=1010;
const int M=10010;

// struct edge
// {
//     // int from;
//     int to;
//     edge(int to):to(to){}
// };

// struct node
// {
//     int number;
// };

int dis[N][N];
int vis[N];
int count[N];

// vector<edge> Graph[N];
set<int> n_pastures;

// bool DFS(int from,int step)//是要找几个点而不是能不能跑通全图
// {
//     if(step==n)
//     {
//         return true;
//     }
//     else
//     {
//         for(int i=1;i<=n;i++)
//         {
//             if(dis[from][i]&&!vis[i])
//             {
//                 vis[i] = true;
//                 if(DFS(i,step+1))
//                 {
//                     return true;
//                 }
//                 vis[i] = false;
//             }
//         }
//     }
//     return false;
// }

void DFS(int from)
{
    vis[from] = true;
    count[from]++;
    for(int i=1;i<=n;i++)
    {
        if(dis[from][i]&&!vis[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    cin>>k>>n>>m;
    for(int i = 0; i < k; i++)
    {
        int temp;
        cin>>temp;
        n_pastures.insert(temp);
    }
    memset(dis, 0, sizeof(dis));
    for(int i=0;i<m;i++)
    {
        int from, to;
        cin>>from>>to;
        dis[from][to]=1;//让奶牛去找点 就不必反向建图了
    }

    int num=0;
    int d=0;
    memset(count, 0, sizeof(count));
    for(auto element=n_pastures.cbegin();element!=n_pastures.cend();++element)
    {
        memset(vis, false, sizeof(vis));
        d++;
        DFS(*element);
    }

    for(int i=1;i<=n; i++)
    {
        if(count[i]==d)
        {
            num++;
        }
    }

    cout<<num<<endl;
    return 0;
}
/*
做题总结
最开始理解错了，程序写的是从奶牛聚集地是否能遍历全图，建立的反向边
但其实本题只需判断点与点之间的连通性
只要同时满足可达就就可以去。
至于用深度搜索还是广度搜索我觉得都可以，BFS涉及到排序的问题了


建立反向边也可以完成事实上
对每个点进行一次最短路，能到所有有奶牛的点就+1
*/