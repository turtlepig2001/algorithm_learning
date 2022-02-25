## c++中的lower_bound()和upper_bound()
两个函数都需要导入头文件algorithm
```c++
#include <algorithm>
```
&emsp;&emsp; 此外还有一个常见的函数是binary_search()，与上述两个函数都是针对于有序序列（因为他们都使用二分查找）。  
* lower_bound(查找的起始位置，查找的终止为止，需要查找的数 )是返回第一个**大于等于**需要查找的数的数的地址  
* 如lower_bound(a,a+n,4)-a; 返回数组a中大于4的下标
* upper_bound()返回第一个**大于**需要查找的数的数的地址
* binary_search()试图在已排序的[first, last)中寻找元素value。如果[first, last)内有等价于value的元素，它会返回true，否则返回false，**它不返回查找位置**
* 注意这三个函数的范围都是[first, last)左闭右开
* 原始upper lower 要求数组是从小到大排列的有序数组

&emsp;&emsp;对于需要查找小于或小于等于，可以通过修改比较器达到目的，数组需要从大到小排列
&emsp;&emsp;首先定义比较函数
```c++
bool cmp(const int &a,const int &b)
{
    return a>b;
}

int pos;
pos=lower_bound(a+1,a+n+1,s，cmp)-a;
```
&emsp;&emsp;也可以不写cmp函数，将所有cmp的位置换成greater<**int**>()

&emsp;&emsp;equal_range的返回值本质上结合了lower_bound和upper_bound两者的返回值。其返回值是一对iterator i 和 j ， 其中i是value可安插的第一个位置，j则是value可安插的最后一个位置。可以推演出：[i，j)中的每个元素都等价于value，而且[i, j)是[first, last)之中符合上述性质的一个最大子区间。  算法lower_bound返回该range的第一个iterator， 算法upper_bound返回该range的past-the-end iterator，算法equal_range则是以pair的形式将两者都返回。
&emsp;&emsp;实例：
```c++
vector<int> nums;
 nums.push_back( -242 );
 nums.push_back( -1 );
 nums.push_back( 0 );
 nums.push_back( 5 );
 nums.push_back( 8 );
 nums.push_back( 8 );
 nums.push_back( 11 );
 pair<vector<int>::iterator, vector<int>::iterator> result;
 int new_val = 8;  
 result = equal_range( nums.begin(), nums.end(), new_val ); 
cout<< "The first place that " 
 << new_val
 << " could be inserted is before " << *result.first
 << ", and the last place that it could be inserted is before " << *result.second
 << endl;

 //The first place that 8 could be inserted is before 8, and the last place that it could be inserted is before 11
```
