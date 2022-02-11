#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int MAX_N=30;
int p,q;

int vis[MAX_N][MAX_N];

int directions[8][2]=
{
    // {-1,2},{-1,-2},{-2,1},{-2,-1},{1,-2},{1,2},{2,1},{2,-1}
    {-1,-2},{1,-2},{-2,-1},{2,-1},{-2,1},{2,1},{-1,2},{1,2}//为保证字典序，在搜索方向上做一个排序
};

bool DFS(int x, int y, int step,string ans)
{
    if(step==p*q)
    {
        cout << ans << endl<<endl;
        return true;
    }
    else
    {
        for(int i=0;i<8;i++)//遍历相邻节点
        {
            int nx=x+ directions[i][0];
            int ny=y+ directions[i][1];
            char row=nx+'1';//这里需要是字符
            char col=ny+'A';
            if(nx<0||nx>=p||ny<0||ny>=q||vis[nx][ny])//初始点是（0，0）
            {
                continue;
            }
            vis[nx][ny]=true;
            if(DFS(nx,ny,step+1,ans+col+row))
            {
                return true;
            }
            vis[nx][ny]=false;
        }
    }
    return false;//从（x,y）继续进行的搜索不成立
}



int main()
{
    int n;
    cin >> n;
    int number=0;
    while (n--) 
    {
        cin>>p>>q;
        memset(vis, false, sizeof(vis));
        cout<<"Scenario#"<<++number<<":"<<endl;
        vis[0][0]=true;
        if(!DFS(0,0,1,"A1"))
        {
            cout<<"impossible"<<endl<<endl;
        }
    }
    return 0;
}
/*
本题总结：
结合深度优先搜索和宽度优先搜索两道题来看，都是抽象出一种状态
将题目转换为对状态的搜索。
题目要求字典序输出路径：控制方法为，若存在一条路径可以将整张图遍历完，那么一定经过A1点，
那么从A1点开始搜索就首先满足了起始点就是满足字典序的，不用再进行排序，
同时对每个状态的跳转方向做出限制，每次搜索都按照满足字典序的要求跳转，这样搜索到的路径一定是全部满足字典序
此外，关于路径的输出，本题使用字符串直接连接的方式，省去了使用队列或者栈的方法。
*/