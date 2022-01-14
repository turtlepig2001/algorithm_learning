#include <iostream>
using namespace std;

int returnnum=-1;

//应当注意题中的输入序列是单调不减的,利用二分法
int search(int left,int right,int *array,int searchnum)
{
    // left=1;
    // right=n;
    if(left>right)
    {
        return returnnum;
    }
    int middle=left+(right-1)/2;
    if(searchnum==array[middle-1])
    {
        returnnum=middle;
        search(left,middle-1,array,searchnum);
        // return middle;

    }
    else if(searchnum<array[middle-1])
    {
        right=middle-1;
        search(left,right,&array[left-1],searchnum);
    }
    else
    {
        left=middle+1;
        search(left,right,&array[left-1],searchnum);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int *array=new int [n];
    int searchnumarr[m];
    int temp[m];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>searchnumarr[i];
    }
    for(int i=0;i<m;i++)
    {   
        returnnum=-1;
        temp[i]=search(1,n,array,searchnumarr[i]);
    }

    for(int i=0;i<m;i++)
    {
        cout<<temp[i]<<" ";
    }
    delete array;
    return 0;
}

//测试数据
/*
11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6
*/