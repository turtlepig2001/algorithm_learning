#include <iostream>
using namespace std;

const int N=110;
int n;
int coins[N];

int main()
{
    cin>>n;
    cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
        coins[i] = 0;;
    }
    for(int i=0;i<n;i++)//轮次
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)//第i轮不翻第i个硬币  
            {
                cout<<coins[j];
                continue;
            }
            if(coins[j]==1)
            {
                coins[j] = 0;
            }
            else
            {
                coins[j] = 1;
            }
            cout<<coins[j];
        }
        cout<<endl;
    }
    return 0;
}
/*
思考
原先都是正面朝上如果翻一次就是只剩一枚正面朝上 从结果看就相当于只把所有反面朝上的硬币翻了一枚
然后第二次翻得时候你肯定不会再翻上一步翻过的这就翻得没有意义了，肯定有一枚之前没翻过的，相对于上一步翻了一枚反面朝上的硬币的这个结果又是相当于又翻了一枚硬币
他是一个非0则1的过程所以能逆着看
*/
