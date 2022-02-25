#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N=1010;

int n;
// int time[N];

struct t
{
    int id;
    int times;
};

t times[N];


// vector<int> order;

bool cmp(const t &a, const t &b)
{
    return a.times < b.times;
}

int main()
{
    cin >> n;
    double sum = 0;
    double sum1=0;
    double ans;
    for (int i=1;i<=n; i++)
    {
        cin>>times[i].times;
        times[i].id=i;
    }
    sort(times+1,times+n+1,cmp);
    for(int i=1; i<n;i++)
    {
        cout<<times[i].id<<" ";
        sum1+=times[i].times;//注意等待时间是累加的
        sum+=sum1;
    }
    cout<<times[n].id;
    cout<<endl;
    ans=sum/n;
    cout<<fixed<<setprecision(2)<<ans;
    return 0;
}