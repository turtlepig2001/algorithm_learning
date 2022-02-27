#include <iostream>
#include <algorithm>

using namespace std;

int n;
int s;
int a;
int b;

const int N=5010;

struct apple
{
    int height;
    int strength;
};

apple apples[N];

bool cmp(const apple& a, const apple& b)
{
    return a.strength< b.strength;
}

int main()
{
    cin >> n >> s;
    cin >> a >> b;
    for(int i=0; i<n; i++)
    {
        cin >> apples[i].height;
        cin >> apples[i].strength;
    }
    sort(apples,apples+n,cmp);
    int num=0;
    int h=a+b;
    for(int i=0; i<n; i++)
    {
        if(s>=apples[i].strength&&h>=apples[i].height)
        {
            num++;
            s-=apples[i].strength;
        }
    }
    cout<<num;
    return 0;
}
