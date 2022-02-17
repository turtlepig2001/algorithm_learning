#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

const double INF=INT_MAX;
const int N=155;
int n;
int field[N];
double diam[N];
double dis[N][N];
// int vis[N];

struct node
{
    int x,y;//横纵坐标
    double dis(const node &a)
    {
        return sqrt(pow(x-a.x,2)+pow(y-a.y,2));
    }
};

node nodes[N];

//深度优先搜索遍历涂色牧场
void DFS(int from,int id)
{
    field[from]=id;
    // vis[from]=true;
    for (int i = 0; i <n ; i++)
    {
        if(dis[from][i]<INF && !field[i]) //field充当了vis的作用
        {
            DFS(i,id);
        }
    }
}


int main()
{
    cin>>n;
    for (int i = 0; i <n ; i++)
    {
        cin>>nodes[i].x>>nodes[i].y;
    }

    char s[N];//注意输入的矩阵没有空隙，将它作为字符串读入更好

    for(int i=0;i< n; i++)//通过邻接矩阵更新直接相连接的点
    {
        cin>>s;
        // scanf("%s",s);
        for (int j=0;j <n ; j++)
        {
            if(s[j]=='1'||i==j)
            {
                dis[i][j]=nodes[i].dis(nodes[j]);
            }
            else
            {
                dis[i][j]=INF;
            }
        }
    }



    memset(field, 0, sizeof(field));
    int id=0;
    for(int i=0;i<n; i++)
    {
        if(!field[i])
        {
            DFS(i,++id);
        }
    }
        //floyd
    for (int k=0;k<n;k++)
    {
        for (int i=0;i<n; i++)
        {
            for (int j=0;j <n ; j++)
            {
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    //获取每个牧场的直径
    memset(diam, 0, sizeof(diam));

    double maxs[N];
    for(int i=0;i<n; i++)//计算每个牧场中每个牧区到其他牧区的最短路径最大值
    {
        maxs[i]=0.0;
        for(int j=0;j<n;j++)
        {
            if(dis[i][j]<INF)
            {
                maxs[i]=max(dis[i][j],maxs[i]);
            }
        }
        diam[field[i]]=max(maxs[i],diam[field[i]]);//求得牧场直径
    }

    //开始连接寻找新牧场的最小直径
    double dia=0;
    double min_dia=INF;
    for(int i=0;i<n; i++)
    {
        for(int j=i+1;j <n ; j++)
        {
            if(field[i]!=field[j])
            {
                dia=max(max(diam[field[i]],diam[field[j]]),maxs[i]+maxs[j]+nodes[i].dis(nodes[j]));
                //比如说内外圈
                min_dia=min(dia,min_dia);
            }//新牧场的直径不是简单的原来的两个牧场直径相加再加上连接路径的长度
        }
    }

    cout<<fixed<<setprecision(6)<<min_dia;

    return 0;

}

