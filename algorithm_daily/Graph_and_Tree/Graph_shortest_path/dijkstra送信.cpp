#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int flag[N];
int side[N][N]; 
int dis[N]; 
int n; 
void dijkstra()
{
	memset(flag,0,sizeof flag) ;
	memset(dis,0x3f,sizeof dis);
	dis[1]=0;
	int t;
	int i,j;
	for(i=1;i<=n;i++)
	{
		t=0;
		for(j=1;j<=n;j++)
		{
			if((flag[j]==0)&&(t==0||dis[j]<dis[t]))
			{
				t=j;
			}
		}
		flag[t]=1;
		for(j=1;j<=n;j++)
		{
			if(flag[j]==0)
			{
				dis[j]=min(dis[j],dis[t]+side[t][j]);
			}
		}
	}
} 
void over()
{
	int i,j;
	int temp;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			temp=side[i][j];
			side[i][j]=side[j][i];
			side[j][i]=temp;
		}
	}
}
int main()
{
	int m;
	cin>>n>>m;
	memset(side,0x3f,sizeof side);
	int sum=0;
	int x,y,i,p,j;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y>>p;
		side[x][y]=min(side[x][y],p);
	}
	
	dijkstra();
	for(i=1;i<=n;i++)
	{
		sum+=dis[i];
	}
	over();
	dijkstra();
	for(i=1;i<=n;i++)
	{
		sum+=dis[i];
	}
	cout<<sum;
	return 0;
}
