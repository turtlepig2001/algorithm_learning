#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

const int num=100010;
const int INF=INT_MAX;

int m,n;
int sch[num];
int stu[num];
int sat;
long long sum = 0;
int b;

bool bgreater(int x,int y)
{
    return x<y;
}

int check(int mid,int score)
{
    if(abs(score-sch[mid])<sat)
    {
        sat=abs(score-sch[mid]);
    }
    b=score-sch[mid];
    return b;
}

int main()
{
    cin>>m>>n;
    // int max_ =0;
    // int min_ =INF;
    for (int i = 1; i <=m;i++)
    {
        cin>>sch[i];
        // min_=min(min_,sch[i]);
        // max_=max(max_,sch[i]);
    }
    for(int i=1;i<=n;i++)
    {
        cin>>stu[i];
    }
    sort(sch+1,sch+m+1,bgreater);
    int left;
    int right;
    int mid;
    int ans;
    for (int i = 1; i <=n; i++)
    {
        sat=INF;
        left=1;
        right=m+1;
        while(left<=right)
        {
            mid=(left+right)/2;
            if(check(mid,stu[i])==0)
            {
                ans=0;
                break;
            }
            if(check(mid,stu[i])>0)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
            ans=sat;
        }
        sum+=ans;
    }
    cout<<sum;
}