#include <iostream>
using namespace std;


//应当注意题中的输入序列是单调不减的,利用二分法
int search(int left,int right,int array[],int searchnum)
{
    // left=1;
    // right=n;
    if(left==right)
    {
        if (array[left]==searchnum)
        {
            return left;
        }
        else
            return -1;
    }
    int middle=(left+right)/2;
    if(searchnum<=array[middle])
    {
        search(left,middle,array,searchnum);
    }
    else
    {
        search(middle+1,right,array,searchnum);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int array[n];
    int searchnumarr[m];
    int temp[m];
    for(int i=1;i<=n;i++)
    {
        cin>>array[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>searchnumarr[i];
    }
    for(int i=0;i<m;i++)
    {   
        temp[i]=search(1,n,array,searchnumarr[i]);
    }

    for(int i=0;i<m;i++)
    {
        cout<<temp[i]<<" ";
    }
    return 0;
}

//测试数据
/*
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
*/