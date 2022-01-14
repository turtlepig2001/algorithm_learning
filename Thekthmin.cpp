//
// Created by 86184 on 2021-06-21.
//
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

template <typename T>
int partition(T *a, int p, int q){
    T x = a[p];
    int i = p;
    for(int j=p+1;j<=q;j++){
        if(!(x < a[j])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[p], a[i]);
    return i;
}

template <typename T>
T kthElement(T *a, int l, int r, int k){
    if(r <= l){
        return a[l];
    }
    int m = partition<T>(a, l, r);
    int kk = m-l+1;
    if(k == kk){
        return a[m];
    }else if(k<kk){
        return kthElement(a, l, m-1, k);
    }else
    {
        return kthElement(a, m+1, r, k-kk);
    }
}

//生成指定范围的随机数，用于测试
template<typename T>
T *Random(int n,int l,int r)//生成范围在l~r的随机数
{
    T *a=new T[n];
    srand(time(0));  //设置时间种子
    for(int i=0;i<n;i++){
        a[i]=rand()%(r-l+1)+l;//生成区间r~l的随机数
    }
    return a;
}

int main(){
   // int test[10] = {2,3,4,1,7,5,6,10,9,8};
    int k = 0;
    int min=0;
    int max=0;
    cout<<"请输入测试值最小值范围:";
    cin>>min;
    cout<<"请输入测试值最大值范围:";
    cin>>max;
    int num=max-min+1;
    int *test=Random<int>(num,min,max);
    cout<<"生成的数组为:";
    for (int i = 0; i < num; ++i) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    cout<<"请输入所求的元素为第几小:";
    cin>>k;
    cout<<endl;
    cout << kthElement<int>(test, 0, num-1, k)<<endl;
    cout<<"排序后的数组为:";
    for (int i = 0; i < num; ++i) {
        cout<<test[i]<<" ";
    }
    delete test;
}
