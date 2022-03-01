#include <iostream>
#include <algorithm>
#include<queue>

using namespace std;

//从小到大排序 顺序取判断差值是否为一和是否相等 二分查找最小值的最大值

const int N=100010;
int n;
long long power[N];

int group_num;

struct group{
    int num;
    int biggest;
};

group groups[N];

bool cmp(int a, int b)
{
    return a<b;
}


int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>power[i];
    }
    sort(power+1,power+n+1,cmp);
    int l=0;
    for(int i=1;i<=n;i++)
    {
        bool ck=false;
        for(int j=l;j>0;j--)
        //这里不需要再对groups数组排序的原因是，对于考前的group[i]他会一直找完他能连续的所有的数，所以从l倒着添加新数，后面的队列的长度一定是小的，因为他是新开的，前面的是直到新开队列为止的
        {
            if(power[i]-groups[j].biggest==1)
            {
                ck=true;
                groups[j].num++;
                groups[j].biggest++;
                break;
            }
        }
        if(!ck)
        {
            l++;
            groups[l].biggest=power[i];
            groups[l].num=1;
        }
    }
    int ans=groups[1].num;
    for(int i=2;i<=l;i++)
    {
        ans=min(ans,groups[i].num);
    }
    cout<<ans;
    return 0;
}