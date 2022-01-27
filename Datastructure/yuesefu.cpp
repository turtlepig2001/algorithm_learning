#include<iostream>
using namespace std;
void creatcir(int n,int nums[500])
{
	for(int i=0;i<n;i++)
	{
		nums[i]=i+1;
	}
}
void circulaton(int m,int n,int nums[500],int sort[500])//按约定顺序将编号输入sort数组中 
{
	int i=0;//i为计数变量，满m跳出循环将该序号记为0 
	int k=n-1;//数组下标从0开始，类似于一个指针，最初指向第一个位置的前一个位置 
	for(int p=0;p<n;p++)
	{
		while(i!=m)
		{
			k=(k+1)%n;//进行循环
			if(nums[k]!=0)//记为0的个体不再参与计数 
			{
				i++;
			}
		}
		sort[p]=nums[k];
		nums[k]=0;
		i=0; 
	} 
}
int main()
{
	int m,n;
	cin>>m>>n;
	int nums[n];
	int sort[n]; 
	creatcir(n,nums);
	circulaton(m,n,nums,sort);
	for(int i=n-1;i>=0;i--)
	{
		cout<<sort[i];
	}
	return 0;
} 
