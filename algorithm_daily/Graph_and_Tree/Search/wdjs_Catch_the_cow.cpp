#include <iostream>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX_N=100001;

int n,k;

struct status 
{
    int n;
    int t;
    status(int n, int t) : n(n), t(t) {}
};

queue<status> statusQueue;

int vis[MAX_N];

int BFS(int n,int k)//使用宽度优先搜索
{
    statusQueue.push(status(n,0));
    vis[n]=true;
    while(!statusQueue.empty())                       //此处可以参照单源最短路径的写法将vis数组放在while循环中
    {                                                 //更容易理解
        status current = statusQueue.front();
        statusQueue.pop();
        if(current.n==k)
        {
            return current.t;
        }
        for(int i=0;i<3;i++)//添加状态节点
        {
            status next(current.n,current.t+1);//结构体实例化不使用new
            if(i==0)
            {
                next.n--;
            }
            else if(i==1)
            {
                next.n++;
            }
            else
            {
                next.n=2*next.n;
            }
            if(next.n<0||next.n>=MAX_N||vis[next.n])//非法状态
            {
                continue;
            }
            statusQueue.push(next);
            vis[next.n]=true;//该状态已被访问
        }
    }
}

int main()
{
    cin>>n>>k;
    // fill(vis,vis+MAX_N,false);
    memset(vis, false, sizeof(vis));
    int ans=BFS(n,k);
    cout<<ans;
    return 0;
}