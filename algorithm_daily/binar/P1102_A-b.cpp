#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int c;
int n;
const int N=200010;
int num=0;
int arr[N];
int ans[N];

multiset<int> num_count;

// void binarySearch(int x,int left,int right)
// {
//     while(left<=right)
//     {
//         int mid=(left+right)/2;
//         if(arr[mid]==x)
//         {
//             num+=num_count.count(x);
//             return;
//         }
//         else if(arr[mid]>x)
//         {
//             right=mid-1;
//         }
//         else
//         {
//             left=mid+1;
//         }
//     }
// }

// bool bgreater(int x, int y)
// {
//     return x<y;
// }

int main()
{
    cin>>n>>c;
    for(int i=1;i<=n; i++)
    {
        cin>>arr[i];
        ans[i] = arr[i]+c;
        num_count.insert(arr[i]);
    }
    int temp=0;
    // sort(arr+1,arr+n+1,bgreater);
    // sort(ans+1,ans+n+1,bgreater);
    for(int i=1;i<=n; i++)
    {   
        temp=ans[i];
        // binarySearch(temp,1,n+1);
        num+=num_count.count(temp);
    }
    cout<<num;
}

// if(left>right)            这相当于全遍历了
//     {
//         return;
//     }
//     int mid=(left+right)/2;
//     if(arr[mid]==x)
//     {
//         num++;
//     }
//     binarySearch(x,left,mid-1);
//     binarySearch(x,mid+1,right);