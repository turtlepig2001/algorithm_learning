#include <iostream>
#include <algorithm>
using namespace std;

// int days=0;
int num_of_areas;
int deepth_of_areas[100005];
int min_days[100005];

int main()
{
    cin >> num_of_areas;
    for (int i = 0; i < num_of_areas; i++)
    {
        cin >> deepth_of_areas[i];
    }
    min_days[0] = deepth_of_areas[0];
    for (int i = 1; i <num_of_areas;i++)
    {
        if(deepth_of_areas[i]>deepth_of_areas[i-1])
        {
            min_days[i] = min_days[i-1]+(deepth_of_areas[i]-deepth_of_areas[i-1]);
        }
        else
        {
            min_days[i] = min_days[i-1];
        }
    }
    cout<<min_days[num_of_areas-1];
}

/*
说实话面对这道题没什么可行的思路 最能想到的就是模拟但是又不会分独立的区间
有考虑过使用分支和递归的方法
这是网上找到的最好理解的一个解题思路
用f[i]f[i]表示前i个坑所铺设的最少天数

那么要做的只需比较一下当前的a[i]a[i]（就是坑的深度）和a[i-1]a[i−1]，分两种情况：

如果a[i]<=a[i-1]a[i]<=a[i−1]，那么在填a[i-1]a[i−1]时就可以顺便把a[i]a[i]填上，这样显然更优，所以f[i]=f[i-1]f[i]=f[i−1];

否则的话，那么在填a[i-1]a[i−1]时肯定要尽量把a[i]a[i]一块填上，a[i]a[i]剩余的就单独填。。

所以，f[i]=f[i-1]+(a[i]-a[i-1])f[i]=f[i−1]+(a[i]−a[i−1])。

初始化f[1]=a[1]f[1]=a[1]，向后推就行了。

也看到有很多使用差分法解的

*/