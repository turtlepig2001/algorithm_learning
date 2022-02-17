#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int c;
int n;
const int N=200010;
long long num=0;//注意用longlong
int arr[N];
// int ans[N];


bool bgreater(int x, int y)
{
    return x<y;
}

int main()
{
    cin>>n>>c;
    for(int i=1;i<=n; i++)
    {
        cin>>arr[i];
    }
    int temp=0;
    sort(arr+1,arr+n+1,bgreater);
    // int l=1; 
    int r1=1;
    int r2=1;
    for(int i=1;i<=n; i++)
    {   
        while(r1<=n&&arr[r1]-arr[i]<=c)
        {
            r1++;
        }
        while(r2<=n&&arr[r2]-arr[i]<c)
        {
            r2++;
        }
        num+=r1-r2;
    }
    cout<<num;
}

