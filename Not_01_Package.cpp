//
// Created by 86184 on 2021-06-23.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TGods
{
    int id;//物品编号
    float w,v;//重量 价值
    float x;//比例
    TGods():w(0),v(0),x(0){}//初始化
};

bool bgreat(const TGods &x,TGods &y)
{
    return x.v/x.w > y.v/y.w;
}

template <typename T>//将背包问题进行类的封装
class solution{
public:
    int num;
    T limit;//限制最大重量
    TGods *array;
    queue<int>ways;
    T value;//总价值
    T weight;//总重量
    T cc;//剩余容量
    solution(){
        cout<<"请输入货物数目和限制重量"<<endl;
        cin>>num>>limit;
        array=new TGods[num];
        for (int i = 0; i < num; ++i) {
            array[i].id=i+1;
        }
        cout<<"请依次输入各物品重量"<<endl;
        for (int i = 0; i < num; ++i) {
            cin>>array[i].w;
        }
        cout<<"请依次输入各物品价值"<<endl;
        for (int i = 0; i < num; ++i) {
            cin>>array[i].v;
        }
        cc=limit;
    }
    void greedy_solution();
    void show();
    ~solution(){
        delete[] array;//释放内存
    }
};

template<typename T>
void solution<T>::greedy_solution() {
    sort(array,array+num,bgreat);
    for (int i = 0; i < num; ++i) {
        if (cc==0)
            break;
        if (cc>array[i].w)
        {
            array[i].x=1;
            cc-=array[i].w;
            value+=array[i].v;
            weight+=array[i].w;
            continue;
        }
        float x=cc/array[i].w;//此时已经不够一次完整的取出物品了
        array[i].x=x;
        value+=array[i].v*x;
        weight+=array[i].w*x;
        break;
    }
}

template<typename T>
void solution<T>::show() {
    cout<<"max weight:"<<weight<<endl;
    cout<<"max value:"<<value<<endl;
    cout<<"The choice of package are :";
    for (int i = 0; i < num; ++i) {
        if (array[i].x<=0)
        {
            break;
        }
        cout<<"package"<<array[i].id<<"("<<array[i].x<<")"<<"--";
    }
    cout<<endl;
    cout<<"the form of packages is blow:"<<endl;

    for (int j = 0; j < num; ++j) {
        cout<<array[j].id<<"      ";
    }
    cout<<endl;
    for (int i = 0; i < num; ++i) {
        cout<<array[i].w<<"      ";
    }
    cout<<endl;
    for (int i = 0; i <num; ++i) {
        cout<<array[i].v<<"      ";
    }
    cout<<endl;
    for (int i = 0; i < num; ++i) {
        cout<<array[i].x<<"      ";
    }
}
int main()
{
    solution<float> test;
    test.greedy_solution();
    test.show();
    test.~solution();
}
//测试数据
//5 26
//5 6 9 3 5
//7 4 10 3 4