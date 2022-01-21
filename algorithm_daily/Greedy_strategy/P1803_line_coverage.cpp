#include <iostream>
#include<algorithm>
using namespace std;

int n;//number of games
const int games_num=1e6;
int attend_num=1;
struct Game 
{
    int begin;
    int end;

}games[games_num];

bool games_turn(const Game &game1, const Game &game2)
{
    return game1.end < game2.end;
}
bool nums_sort(int a,int b)
{
    return a>b;
}
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>games[i].begin;
        cin>>games[i].end;
    }
    sort(games,games+n,games_turn);
    int temp_end=games[0].end;
    for(int i=0; i<n; i++)
    {
        int j=i+1;
        if(games[j].begin>=temp_end)
        {
            attend_num++;
            temp_end=games[j].end;
        }
    }
    cout<<attend_num;
    return 0;
}

    // for(int i=0; i<n; i++)
    // {
    //     attend_num=0;
    //     attend_num++;
    //     temp_end=games[i].end;
    //     for(int j=i+1; j<n;j++)
    //     {
    //         if(games[j].begin>=temp_end)
    //         {
    //             attend_num++;
    //             temp_end=games[j].end;
    //         }
    //     }
    //     nums[k]=attend_num;
    //     k++;

    // }

/*
    解题总结
    q1：为什么数组排序时要按照结束时间排序、

    网络上的解释：
    在一个数轴上有n条线段，现要选取其中k条线段使得这k条线段两两没有重合部分，问最大的k为多少。

    最左边的线段放什么最好？

    显然放右端点最靠左的线段最好，从左向右放，右端点越小妨碍越少

    其他线段放置按右端点排序，贪心放置线段，即能放就放

    q2：为什么只用一层循环就可以完成计数，而不是像之前的一样使用两层循环导致超时

    解法是按照结束时间排的顺序而之前的双层循环面向的是按照开始时间排序的序列，因此不会出现前面的某个比赛过长覆盖了后面连续的多个比赛（大于等于2）的情况，因此直接贪心策略直接往后尽可能地取即可

    3.其实还应该注意的一点是，排序的时候如果右端点相同应该将开始时间晚的放在前面
    写法：
    bool cmp(node x,node y){
        if(x.end!=y.end)return x.end<y.end;//按结束时间早的在前
        else return x.sta>y.sta;按开始时间晚的在前
    }

    4.关于按照左端点排序（网上的解法）
    思路就是比较当前区间和下一区间，如果下一区间与当前区间没有相交，则由于我们是按左端点排序的，后面的都不会相交，直接选择当前区间；否则这两个区间显然必须抛弃一个，由于我们是按左端点排序的，后面的区间左端点都是大于它们的，因此这两个的左端点已经没有意义了，为了留出更多的空间，留下右端点靠左的那一个即可。
*/