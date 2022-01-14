//
// Created by 86184 on 2021-06-13.
//
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

template <typename T>
bool operator<(const T &x, const T &y){
    return x < y;
}

template<typename T>
void Merge(T *left, int m, T *right, int k,T *all)//最后的归并
{
    //此时左右数组均已排好顺序
    //归并到all[0]-all[m+k-1]中
    int i=0;
    int j=0;
    int l=0;
    while (i<m && j<k)
    {
        if(left[i]<right[j])
        {
            all[l++]=left[i++];
        } 
        else
        {
            all[l++]=right[j++];
        }
    }
    if (l==m)
    {
        while (j<k)
        {
            all[l++]=right[j++];
        }
    }
    if (l=k)
    {
        while(i<m)
        {
            all[l++]=left[i++];
        }
    }
}

template<typename T>
void copy(T *a, T* c, int m)
{
    for (int i = 0; i < m; ++i)
    {
        c[i]=a[i];
    }
}

template<typename T>
void MergeSort(T *a,int left, int right,T *c)
{
    if (left>=right)
    {
        return;
    }
    int middle=(left+right)/2;
    MergeSort(a,left,middle,c);
    MergeSort(a,middle+1,right,c);
    Merge(&a[left],middle-left+1,&a[middle+1],right-(middle+1)+1,c);
    //c[0]~c[right-left+1]有序

    copy(c,&a[left],right-left+1);
}
//随机数生成方法
template <typename T>
T *getRandom(int n) {
    srand((int)time(0));
    T *randnum = new T[n];//存储随机生成数
    for(int i=0;i<n;i++){
        randnum[i] = rand();
    }
    return randnum;
}

int main()
{
    clock_t start,stop;//clock_t 是用来保存时间的数据类型
    long num;
    num=1000000;
    double *randarray_1;
    double *randarray_2;
    double *copy1=new double [num+1];
    double *copy2=new double [num+1];
    randarray_2=new double [num];
    randarray_1=getRandom<double>(num);
    for (int i = 0; i < num; ++i) {
        randarray_2[i]=randarray_1[i];
    }
    start=clock();//这个函数返回从“开启这个程序进程”到“程序中调用clock()函数
                  // ”时之间的CPU时钟计时单元（clock tick）数，
                  // 在MSDN中称之为挂钟时间（wal-clock）
    MergeSort<double>(randarray_1,0,num,copy1);
    stop=clock();
    cout<<"The costs of my algorithm is"<<double (stop-start)/CLOCKS_PER_SEC<<"s"<<endl;
    //常量CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元
    start=clock();
    sort(randarray_2,randarray_2+num);
    stop=clock();
    cout<<"The costs of STL's sort is"<<double (stop-start)/CLOCKS_PER_SEC<<"s"<<endl;

    delete randarray_1;
    delete randarray_2;
    delete copy1;
    delete copy2;
}