#include <iostream>
#include <algorithm>
using namespace std;

int n;
int maximum;
int multiple=1;

struct person 
{
    int left;
    int right;
    int multiple;
}persons[1010];

bool bgreater(person a, person b)
{
    return a.multiple<b.multiple;
}


int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> persons[i].left;
        cin >> persons[i].right;
        persons[i].multiple=persons[i].left*persons[i].right;
    }
    sort(persons+1,persons+n+1,bgreater);
    // multiple=persons[0].left;
    maximum=persons[0].left/persons[1].right;
    for (int i =1;i<=n;i++)
    {
        multiple=multiple*persons[i-1].left;
        if(multiple/persons[i].right>maximum)
        {
            maximum=multiple/persons[i].right;
        }
    }
    cout<<maximum;
    return 0;
}
