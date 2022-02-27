#include <iostream>
#include <algorithm>

using namespace std;

const int M=5010;

int n,m;

struct farmer
{
    int price;
    int quantity;
};

farmer farmers[M];

bool cmp(const farmer & a, const farmer & b)
{
    return a.price < b.price;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>farmers[i].price>>farmers[i].quantity;
    }
    sort(farmers,farmers+m,cmp);
    int ans=0;
    for (int i=0;i<m;i++)
    {
        if(n<=0)
        {
            break;
        }
        else
        {
            if(n>=farmers[i].quantity)
            {
                n-=farmers[i].quantity;
                ans+=farmers[i].quantity*farmers[i].price;
                continue;
            }
            ans+=n*farmers[i].price;
            n=0;
        }
    }
    cout<<ans;
    return 0;
}