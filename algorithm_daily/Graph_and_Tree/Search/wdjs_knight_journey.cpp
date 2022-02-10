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
    {-1,2},{-1,-2},{-2,1},{-2,-1},{1,-2},{1,2},{2,1},{2,-1}
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