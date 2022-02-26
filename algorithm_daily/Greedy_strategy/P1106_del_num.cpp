#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string n;
int k;
int num[210];
int need;
int cnt = 0;

bool sign=0;

int main()
{
    cin>>n;
    cin>>k;
    for(int i = 0; i <n.length();i++)
    {
        num[i+1]=n[i]-'0';//由字符串转换成数
    }

    int t=1;
    need=n.length()-k;//留下的数字个数
    while(cnt<need)
    {
        int mint=t;
        for(int i=t;i<=t+k;i++)
        {
            if(num[i]<num[mint])
            {
                mint=i;
            }
        }
        if(num[mint])
        {
            sign=1;
        }
        if(sign)//前面已经有非零数 即使这个数是0也应当输出
        {
            cout<<num[mint];
        }
        
        k=k-(mint-t);
        t=mint+1;
        cnt++;
    }
    if(!sign)//前导0问题
    {
        cout<<0;
    }
    return 0;
}

/*
解题思路：
按位考虑，首先保证第一位数是最小的（因为最后得到的数字位数是固定的），对于第一位数，可以选择的范围是有限的，
最多只能在前k+1个数中选择
第二位第三位...同理，这时k要根据已经删除的数动态变化，直到达到个数要求，将这一位当作第一位重复这样的操作
这利用了一种贪心思想，优先考虑最高位，最高位小才能保证总体最小
*/
