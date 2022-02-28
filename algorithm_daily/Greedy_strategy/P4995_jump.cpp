#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

const int N=310;
int n;

struct stone
{
    int height;
    int h_ground;
    // stone(int height):height(height),h_ground(height*height){}
};

bool cmp(const stone & a, const stone & b)
{
    return a.height<b.height;
}

stone stones[N];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>stones[i].height;
        stones[i].h_ground=stones[i].height*stones[i].height;
    }
    sort(stones+1,stones+1+n, cmp);
    long long ans=0;
    int left=1;
    int right=n;
    ans+=stones[right].h_ground;//从最高处跳上石头
    int num=1;
    bool direct=false;//f向左r向右


    //参照实例应该是不允许跳下
    while(num!=n)
    {
        if(direct)//方向向右
        {
            ans+=pow(stones[right].height-stones[left].height,2);
            left++;
            num++;
            direct=false;
        }
        else
        {
            ans+=pow(stones[right].height-stones[left].height,2);
            right--;
            num++;
            direct=true;
        }
    }
    cout<<ans;
    return 0;
}