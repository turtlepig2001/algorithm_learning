//分治与递归之一元三次方程求解
//此题要用实数二分的概念

/*

实数二分模板
bool check(double x) {... } // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}

*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

const double gap=0.0001;
// double *tempans=new double [3];
// int count=0;
double a,b,c,d;
double fouction(double x)
{
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}

//函数解必定落在某个长度为1的区间内分别在每个区间内找
void search(double left, double right)
{
    if(fouction(left)==0)
    {
        cout <<fixed<<setprecision(2)<<left<< " ";
    }
    else if(fouction(left)*fouction(right)<0)//right和left之间必然有解
    {
        while(right-left>gap)
        {
            double mid=(right+left)/2;
            if(fouction(mid)*fouction(left)<0)
            {
                right=mid;//下标本身就是数不需要递归调用函数
            }
            else
            {
                left=mid;
            }
        }
        //精度足够小了
        cout <<fixed<<setprecision(2)<<left << " ";//不加fixed控制的是全部位数为2，加了fixed意味着是固定点方式显示
    }

}


int main()
{
    cin>>a>>b>>c>>d;
    int j=0;
    for(int i=-100;i<=100;i++)
    {
        j=i+1;
        search(i,j);
    }
    return 0;
}
/*

解题总结
这道题使用了枚举+分治的解法
应当注意到题目所给的解范围是-100到100的固定范围，且解之间的距离大于1
还有就是要注意到题目所给的那个性质
因此可以将固定范围划分为常数个区间，从左到右判断二百个区间内是否有解
对于每个区间可以使用分治算法，因为这个区间里最多只有一个解了

这道题的特点是他的解不一定正好在整数点上，需要实数二分的概念
最初解的时候直接考虑在整个范围进行二分法，直接对半分不清楚每个区间内到底有多少个解
加上一元三次的函数特点，很难利用题目所提示的性质

对实数二分模板的理解：这里esp应该是精度的意思 最初将其当作1 所以肯定无法求解

*/