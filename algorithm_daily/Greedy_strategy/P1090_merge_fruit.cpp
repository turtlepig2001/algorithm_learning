#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

// const int category_num=1e4;
// int nums[category_num];
long long sum=0;
int n;

priority_queue<int,vector<int>,greater<int> >nums_queue;

int main()
{
    cin >> n;
    int temp=0;
    for (int i=0; i<n;i++)
    {
        cin >> temp;
        nums_queue.push(temp);
    }
    int num1=0;
    int num2=0;
    while (nums_queue.size()!=1)
    {
        num1=nums_queue.top();
        nums_queue.pop();
        num2=nums_queue.top();
        nums_queue.pop();
        sum+=num1;
        sum+=num2;
        nums_queue.push(num1+num2);
    }
    cout<<sum;
    return 0;
}
/*
解题总结
最开始的思想是：将存数目的数组从小到大排序后两个两个向后加起来（我甚至没想到要加和放回去后要排序的）
感觉是有点像学数据结构的时候画那个哈夫曼树（希望没记错），每次找两个最小的合起来
如果每次都排一次应该是会超时
优先队列很好用会自动地排好序而且不用管想数组那样的下标问题（数组也不难主要是需要每次用一次排序算法）
既然他像哈夫曼树，那应该就是用树也能做的，看标签是使用二叉堆，这个后面复习了图树、堆再换种方法
*/
