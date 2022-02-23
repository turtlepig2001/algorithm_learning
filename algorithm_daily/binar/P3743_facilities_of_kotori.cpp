#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n,p;

const int N = 100010;

double a[N],b[N];
double sum = 0;

bool check(double mid)
{
    double charge=p*mid;
    for(int i=1;i<=n; i++)
    {
        if(a[i]*mid>b[i])
        {
            sum+=a[i]*mid-b[i];
        }
    }
    return charge>sum;
}


int main()
{
    cin >> n >> p;
    for(int i=1;i<=n; i++)
    {
        cin >> a[i];
        cin >> b[i];
        sum+=a[i];
    }
    if(sum<=p)
    {
        cout << -1 << endl;
        return 0;
    }
    double left=0;
    double right=1e10;
    double mid;
    double ans;
    while(right-left>1e-6)
    {
        sum=0;
        mid=(left+right)/2;
        if(check(mid))
        {
            left=mid;
            ans=mid;
        }
        else
        {
            right=mid;
        }
    }
    cout<<fixed<<setprecision(6)<<ans;
    return 0;
}
/*
本题最大的一个注意点是充电连续放电连续且切换充电时不计时间
这时就不需要再考虑具体的充电策略，直接计算需要消耗的能量总和即可
自己在思考问题时思考的过于复杂了
首先使用二分法确定一个可能时间，
在这个时间内如果消耗的能量大于该设备存储的能量那么就可以将此设备忽略
小于的，记录需要的能量总和，与充电宝能提供的能量总和进行对比，如果小于等于则当前时间时满足情况的
*/