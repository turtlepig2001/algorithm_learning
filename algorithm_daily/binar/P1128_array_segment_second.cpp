#include <iostream>
#include <algorithm>
using namespace std;

int N,M;
const int num_of_array=1e8;
int A[num_of_array+1]={0};
int B[num_of_array+1]={0};//前缀和
int sum_of_array=0;
// int max_length_of_segment;

bool check(int maxsum)
{
    // int num=0;
    // // int length=0;
    // int now=0;
    // for(int i=1;i<=N; i++)
    // {
    //     if((B[i]-B[now])>maxsum)
    //     {
    //         num++;
    //         now=i-1;
    //     }
    // }
    // return num<=M;
    int num=1;//注意这里是1
    int sum=0;
    for(int i=1;i<=N; i++)
    {
        if((sum+A[i])>maxsum)//超出长度新起一段
        {
            sum=A[i];
            num++;
        }
        else
        {
            sum+=A[i];
        }
    }
    return num<=M;

}


int main()
{
    cin>>N >>M;
    int max=0;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
        if(A[i]>max)
        {
            max=A[i];
        }
        sum_of_array+=A[i];
        B[i]=sum_of_array;
    }

    int left=max;//严格的讲左边界确实是数组中的最大值，如果设为0或1平台测试时第四个数据点会有问题
    int right=B[N];
    int mid;
    int ans;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(check(mid))
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    cout<<ans;
    return 0;
}

/*
check只需要检验mid是否满足条件（即合法）
最小的判断由二分答案来完成
这道题的解决就像是逆向思维，因为如果正向的去思考分段方式的话会存在很多种可能即使遍历也是很难
而二分的选择一个最大长度去判断一整个数组是否全部满足分段小于等于这个长度，加上下一个数仍小于就将这个数加入若大于就新起一段，从而忽略了具体怎么分段，只需他是最大即可
最大值的最小化由二分法来完成
关于左侧边界的网络解释：左端点必须从最大值开始，因为如果选择了一个小的，贪心算法还是将超过这个值看作一段
*/