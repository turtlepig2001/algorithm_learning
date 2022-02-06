# 图论之最短路径理解

## 一、迪杰斯特拉算法

需要引进两个集合 S、U，S记录已求出最短路径的顶点而U记录尚未求出最短路的顶点集合。  
操作步骤如下：  
1.初始化，S仅包含顶点s，U包含其他顶点，U中顶点的距离为s到该点的距离，最初初始化为∞,初始化方式：


```c++
fill(dis+1,dis+n+1,INF);
```

2.从U中选择距离s最短的一个顶点k，将顶点k加入到S中，同时在U中移除k；
在这里S使用一个优先队列进行简单的堆优化，按照距离小的点自动排列，如下：
定义节点时：
```c++
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
```
在节点定义时进行运算符重载，按照距离顶点的距离从小到大排列
```c++
#include <queue>
priority_queue<node> mypriority_queue;
```
3.更新U中各个顶点到起点s的距离。之所以更新U中顶点的距离，是由于上一步中确定了k是求出最短路径的顶点，从而可以利用k来更新其他顶点的距离；例如，(s, v)的距离可能大于(s, k)+(k, v)的距离。
在其中，设置一个vis[ ]数组，对于已经拓展（当前已找到最短路径）过的节点，跳过重复过程，减少时间复杂度（这是为了防止有些oj题无法通过实现限制）；
判断过程为
```c++
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
```

4.重复2、3步，直到遍历完所有节点。

### 个人理解
如果我们从最初的原点开始模拟一遍整个过程：  
1.最开始只有原点s，取出，出队（这时队列空），对与s相连的所有节点进行遍历，读取第一个（这里是按照最近顺序排序的），再判断原先记录的到原点的距离与通过s点到该点的距离（事实上，最开始时是直接将直接连接的点的记录值又无穷大更新为边距离），如果小于则可以认为在当前情况下获得了最短距离，并将该点入队，遍历完所有与s连接的点（若小于则认为当前记录的距离值是小值）；  

2.再从与原点直接相连的某一点出发将其作为新的原点重复上述过程。  
3.优先队列首先出队的始终是距离原点距离最小的一个节点（假设a点于s点直连长度为5，s与b点直连路径长2，b与a之间路径长度为2，队列中首先取出的一定是b），这保证了中间点已经是最短距离。  
4.实际上，Dijkstra 算法是一个排序过程，是根据原点到图中其余点的最短路径长度进行排序，路径越短越先被找到，路径越长越靠后才能被找到。  




完整迪杰斯特拉算法模板如下：
参照洛谷P4779单源最短路径
```c++
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
                mypriority_queue.push(node(t,dis[t]);//相当于找到最短路径添加到S的过程（如果已经是添加节点中最短的）
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

```

## 二、弗洛伊德（Floyd）算法

### （一）Floyd算法思想  
&emsp;&emsp;Floyd算法是一个经典的动态规划算法。  
&emsp;&emsp;从任意节点i到任意节点j的最短路径不外乎2种可能，一是直接从i到j，二是从i经过若干个节点k到j。所以，我们假设Dis(i,j)为节点u到节点v的最短路径的距离，对于每一个节点k，我们检查Dis(i,k) + Dis(k,j) < Dis(i,j)是否成立，如果成立，证明从i到k再到j的路径比i直接到j的路径短，我们便设置Dis(i,j) = Dis(i,k) + Dis(k,j)，这样一来，当我们遍历完所有节点k，Dis(i,j)中记录的便是i到j的最短路径的距离。

### （二）算法过程
​&emsp;&emsp;1.首先把初始化距离dist数组为图的邻接矩阵，路径数组path初始化为-1（一些题目中不需要记录路径）。其中对于邻接矩阵中的数首先初始化为正无穷，如果两个顶点存在边则初始化为权重。  
​&emsp;&emsp;2.对于每一对顶点 u 和 v，看看是否存在一个顶点 w 使得从 u 到 w 再到 v 比己知的路径更短。如果是就更新它。  
&emsp;&emsp;状态转移方程为:  
&emsp;&emsp;如果 dist[i][k]+dist[k][j] < dist[i][j]  
&emsp;&emsp;则dist[i][j] = dist[i][k]+dist[k][j]  
###  （三）主要代码
未加入优化：
```c++
for(int k=1;k<=n;++k)
    for(int i=1;i<=n;++i)
        for(R int j=1;j<=n;++j)
            dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
```
加入优化vis[]数组：
```c++
//每次枚举k时都要判定在w时可不可以到这个点，并且看是否标记了k。(洛谷P1119)
for(int k=0;k<n;k++)
{
	if(t[k]<=w&&!vis[k])
	{
		vis[k]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(f[i][j]>f[i][k]+f[k][j])
				    f[i][j]=f[i][k]+f[k][j];
		}
}
```
### （四）模板题
&emsp;&emsp;洛谷P1119
```c++
//用弗洛伊德算法求解P1119
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;
const int N=210;
// const int M=N*(N-1)/2;

const int length=1e9;//道路的最大长度 
/*
length不可以设置为稍大于10000的数也不能设置为INF  应设置为较大的数如1e9
*/
int n;//村庄数目
int m;//公路数目

int q;//nums_of_query

int t[N];//time
int cost[N][N];//
// int vis[N];//已经拓展了的节点要省去遍历过程

void Floyd(int k)
{
    for(int i=0;i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if (cost[i][j]>(cost[i][k]+cost[k][j]))
            {
                cost[i][j]=cost[i][k]+cost[k][j];
                cost[j][i]=cost[i][j];//双向道路记得要同时更新
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }
    fill(cost[0],cost[0]+N*N,length);
    for (int i = 0; i < n; i++)
    {
        cost[i][i]= 0;
    }
    for(int i=0;i<m;i++)
    {
        int from,to,len;
        cin>>from>>to>>len;
        cost[from][to]=len;
        cost[to][from]=len;//公路是双向的
    }
    cin>>q;
    int now=0;
    int ans[q];
    for(int i=0;i<q; i++)
    {
        int x,y,time;
        cin>>x>>y>>time;
        // if(t[x]>time||t[y]>time)
        // {
        //     ans[i]=-1;
        //     continue;
        // }
        // else if(time!=now)//时间增加要更新
        // {
        //     now=time;
        //     for(int i=0;i<n;i++)
        //     {
        //         if(t[i]<=time)
        //         {
        //             Floyd(i);
        //         }
        //     }
        // }
        // if(cost[x][y]<length)
        // {
        //     ans[i]=cost[x][y];
        // }
        // else
        // {
        //     ans[i]=-1;
        // }
        while(t[now]<=time&&now<n)
        {
            Floyd(now);
            now++;
        }
        if(t[x]>time||t[y]>time||cost[x][y]==length)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=cost[x][y];
        }
    }
    for(int i=0;i<q; i++)
    {
        cout<<ans[i]<<endl;
    }
    return 0;
}
```
&emsp;&emsp;关于本题的理解：  
&emsp;&emsp;1.这个算法的主要思路，就是通过其他的点进行中转来求的两点之间的最短路。因为我们知道，两点之间有多条路，如果换一条路可以缩短距离的话，就更新最短距离。而它最本质的思想，就是用其他的点进行中转，从而达到求出最短路的目的。  
&emsp;&emsp;2.弗洛伊德算法的基本思想就是，最开始只允许经过1号顶点进行中转，接下来只允许经过1和2号顶点进行中转……允许经过1~n号所有顶点进行中转，求任意两点之间的最短路程。用一句话概括就是：从i号顶点到j号顶点只经过前k号点的最短路程。（而不是只允许第k个节点）  
&emsp;&emsp;3.题意：所有的边全部给出，按照时间顺序更新每一个可用的点（即修建好村庄），对于每个时间点进行两点之间询问，求对于目前建设的所有村庄来说任意两点之间的最短路。  
&emsp;&emsp;4.可以看到程序q次询问的部分中，注释部分使用的办法是：对于每次询问都进行从0到k的遍历，事实上造成了很多次重复的循环。因为题目给出的重建时间是单调不减的，同时q次询问的时间也同样是单调的时间，所以新的方法设置了一个now指向现在已经建起的村庄，就相当于Floyd算法中逐渐添加节点的操作。后面时间的询问可以使用原先已经更新过的图，在其中添加新的节点即可。  
&emsp;&emsp;5.但是本题和单纯的Floyd算法又稍有不同：因为我们需要考虑在询问时间点的起始点是否已经建立起来，如果有任意一个未能建完，就要赋值-1并跳过。但是实际上跳过并不对，因为now++后再在某个时间点有些村庄建完了，但这时算法中的那个“k”值已经跳过去了，可能对于某些k值，图中新加的节点会使某些路径更短，但已经没法更新了。所以程序中的方法是，先进行全图更新（因为边、点这些值我们都是知道的，建设时间的限制无非是后天限制），在更新后再判断起始节点是否满足时间限制。  
&emsp;&emsp;6.至于length值的设置，只能说是太小可能会等于相加值，还是应该设置为很大的数，但是太大有可能会变成负数（至于为何我也没有太好的理解）。
