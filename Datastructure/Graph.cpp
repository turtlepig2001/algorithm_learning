//
// Created by 86184 on 2020-12-09.
//
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define Vnum 100
//下面关于定义邻接表
typedef struct EdgeNode//弧结点结构
{
    int adjvex;//该边所指向的顶点的序号
    struct EdgeNode *nextvex;//指向下一条边
}*graphvex;
typedef struct//顶点结点结构
{
    int vertex;//顶点信息
    struct EdgeNode *link;//指向第一条依附该顶点的弧
}VexNode;
int visted[Vnum]={0};
typedef VexNode adj_list[Vnum];
//下面建立邻接表
void buildadjlist(adj_list &adjList,int n,int e)
{
    for (int i = 0; i < n; ++i)//初始化邻接表
    {
        adjList[i].vertex=i;
        adjList[i].link=NULL;
    }
    int i,j;//定义顶点对
    for (int k = 0; k < e; ++k)//读入顶点对
    {
        cout<<"请输入顶点对:";
        cin>>i>>j;
        graphvex p=new EdgeNode;
        p->adjvex=j;
        p->nextvex=adjList[i].link;
        adjList[i].link=p;
        graphvex q=new EdgeNode;
        q->adjvex=i;
        q->nextvex=adjList[j].link;
        adjList[j].link=q;//这样就建立成了无向图，课本定义为有向图，导致之前的遍历结果是按照有向图的遍历来执行的
    }
}
//下面是图的遍历算法
//深度优先搜索
void dfsearch(adj_list adjList,int v0)//递归算法
{
    cout<<"["<<v0<<"]";
    visted[v0]=1;
    graphvex p=adjList[v0].link;
    while (p!=NULL)
    {
        if (visted[p->adjvex]==0)
            dfsearch(adjList,p->adjvex);
        p=p->nextvex;
    }
}
void nrpdfsearch(adj_list adjList,int v0)//非递归算法
{
    stack<graphvex> assiststack;//建立辅助栈
    cout<<"["<<v0<<"]";
    visted[v0]=1;
    int num=0;//辅助变量
    graphvex p=adjList[v0].link;
    while (p!=NULL||!assiststack.empty())
    {
        while (p!=NULL)
        {
            if (visted[p->adjvex]==1)
                p=p->nextvex;
            else
            {
                num=p->adjvex;
                cout<<"["<<num<<"]";
                visted[num]=1;
                assiststack.push(p);
                p=adjList[num].link;
            }
        }
        if (!assiststack.empty())
        {
            p=assiststack.top();
            assiststack.pop();
            p=p->nextvex;
        }
    }
}
//广度优先搜索
void bfsearch(adj_list adjList,int v0)
{
    queue<int> assistqueue;//建立辅助队列
    int v=0;//辅助变量
    visted[v0]=1;
    cout<<"["<<v0<<"]";
    graphvex p=new EdgeNode;
    p->nextvex=adjList[v0].link;
    do {
        while (p!=NULL)
        {
            v=p->adjvex;
            if (visted[v]==0)
            {
                cout<<"["<<v<<"]";
                assistqueue.push(v);
                visted[v]=1;
            }
            p=p->nextvex;
        }
        if (!assistqueue.empty())
        {
            v=assistqueue.front();
            assistqueue.pop();
            p=adjList[v].link;
        }
    }while ((p!=NULL)||(!assistqueue.empty()));
}
void count_component(adj_list adjList,int n) //求图的连通分量，n为顶点数
{
    int count=0;
    for (int i = 0; i <n ; ++i) {
        if (visted[i]==0)
        {
            cout<<"连通分量"<<count<<"包含以下顶点:";
            dfsearch(adjList,i);
            count++;
            cout<<endl;
        }
    }
    cout<<"共有"<<count<<"个连通分量"<<endl;
}
int main()
{
    VexNode adj_list[Vnum];
    int n,e;
    cout<<"请输入顶点数和边数:";
    cin>>n>>e;
    buildadjlist(adj_list,n,e);
    int v0;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"请输入要的遍历起点:";
    cin>>v0;
    dfsearch(adj_list,v0);
    cout<<"这是图的深度优先搜索（递归算法）"<<endl;
    cout<<endl;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"请输入要插入遍历起点:";
    cin>>v0;
    nrpdfsearch(adj_list,v0);
    cout<<"这是图的深度优先搜索"<<endl;
    cout<<endl;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"请输入要插入遍历起点:";
    cin>>v0;
    cout<<"这是图的深度广度搜索"<<endl;
    bfsearch(adj_list,v0);
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    count_component(adj_list,n);
    return 0;
}

