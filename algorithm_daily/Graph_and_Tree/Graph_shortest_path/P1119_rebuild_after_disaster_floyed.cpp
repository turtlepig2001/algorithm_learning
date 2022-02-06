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

void Floyed(int k)
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
        //             Floyed(i);
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
            Floyed(now);
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

