//
// Created by 86184 on 2020-12-19.
//
#include <iostream>
using namespace std;
typedef struct Node
{
    int num;
    struct Node *next;
}*Pointer;
Pointer craetlist(int n)
{
    Pointer Head;
    Head=new Node;
    Pointer p=Head;
    p->num=1;
    for (int i = 2; i <=n ; ++i)
    {
        Pointer q=new Node;
        q->num=i;
        p->next=q;
        p=q;
    }
    p->next=Head;//建立循环链表
    return Head;
}
void circullist(int m,Pointer Head, int sorts[500])
{
    Pointer p1,p2;
    p1=Head;
    p2=p1;//初始为空，头尾相接
    while (p2->next!=Head)
    {
        p2=p2->next;
    }//将p2进行到p1的后面
    int sort=0;
    while (p1->next!=p1)
    {
        for (int i = 1; i < m; ++i) {
            p1=p1->next;
            p2=p2->next;
        }
        sorts[sort]=p1->num;
        sort++;
        p2->next=p1->next;
        delete p1;
        p1=p2->next;
    }
    sorts[sort]=p1->num;
    delete p1;
}
int main()
{
    int m,n;
    cin>>m>>n;
    int sorts[n];
    Pointer Head=craetlist(n);
    circullist(m,Head,sorts);
    for (int i = n-1; i >=0; i--)
    {
        cout<<sorts[i];
    }
    return 0;
}
