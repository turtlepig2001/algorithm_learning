//
// Created by 86184 on 2021-06-23.
//
#include <iostream>
#include<algorithm>
#include<fstream>
#include<queue>
#include<functional>
#include<string>
#include<vector>
#include <sstream>

using namespace std;
struct TN
{
    char c;
    int f;
    int idx;//线性表中位置索引标号
    int p;//父亲线性表中的标号
    int l, r;//左右节点的索引号
    TN() :p(-1), l(-1), r(-1) {}
};
struct CN
{
    char c;//字符
    int num;//个数
    int len;//编码长度
    CN() :num(0), len(0) {}
};
class CHuffman
{
public:
    CHuffman();
    ~CHuffman();
    CHuffman(char *c); //用文件中作为构造函数的参数
    void CreateTree();//生成编码树
    void OutputTree();//打印编码树
    void OutputCode();//打印编码
    void XCode();//Huffman编码
    //void DeCode(int b[], int m);
    void INCH() { h_c = new CN[260]; h_n = h_sum = 0; }//初始化 最多256个ASCII码
    int printCode(TN node);//打印某个字符的编码
    void OutputInformation();
private:
    TN *h_t;//线性表
    int h_n;//字符种类个数
    int h_sum;//字符总个数
    CN *h_c;//统计字符数及其个数
};
CHuffman::CHuffman() {}
CHuffman::~CHuffman()
{
    delete[]h_t;
    delete[]h_c;
}
bool operator>(const TN &x, const TN &y) { return x.f > y.f; }
void CHuffman::XCode()
{
    h_t = new TN[2 * h_n];//n个字符创建2n-1个结点
    for (int i = 0; i < h_n; i++)//初始化操作
    {
        h_t[i].c = h_c[i + 1].c;
        h_t[i].f = h_c[i + 1].num;
        h_t[i].idx = i;
        //读入c,f,idx
    }
    std::priority_queue<TN, std::vector<TN>, std::greater<TN> >PQ;//优先队列
    for (int i = 0; i < h_n; i++)
    {
        PQ.push(h_t[i]);
    }
    int next = h_n;//下一个要生成的节点
    while (!PQ.empty())
    {
        TN l = PQ.top();
        PQ.pop();
        TN r = PQ.top();
        PQ.pop();
        TN p;
        p.l = l.idx; p.r = r.idx;
        p.f = l.f + r.f;
        p.idx = next;
        h_t[next] = p;
        h_t[l.idx].p = h_t[r.idx].p = next;
        PQ.push(p);
        next++;
        if (next == 2 * h_n - 1) { break; }
    }
}
int CHuffman::printCode(TN node)
{
    cout << "(" << node.c << ":";
    std::vector<int> v;
    while (node.p != -1)
    {
        if (node.idx == h_t[node.p].l)//是左孩子
        {
            v.push_back(0);
        }
        else
        {
            v.push_back(1);
        }
        node = h_t[node.p];
    }
    int cc = v.size();
    for (int k = v.size() - 1; k >= 0; k--)
    {
        cout << v[k];
    }
    cout << ") ";
    return cc;
}
CHuffman::CHuffman(char *c)
{
    INCH();
    int n(0);//已有标志；有为1，无为0

    ifstream fin("C:/Users/86184/Desktop/test.txt", ios::in);
    if (!fin)
    {
        cout << "File open error!\n";
        return;
    }
    char ch;
    while ((ch = fin.get()) != EOF)
    {
        //cout << ch;
        h_sum++;
        for (int i = 1; i <= h_n; i++)
        {
            if (h_c[i].c == ch)//匹配字符
            {
                h_c[i].num++;
                n = 1;
                i = h_n + 1;//跳出循环
            }
        }
        if (n == 0)
        {
            h_n++;
            h_c[h_n].c = ch;//新字符
            h_c[h_n].num++;
        }
        else
        {
            n = 0;
        }

    }
    //cout << endl;
    cout<<"以下是字符统计数据:"<<endl;
    cout << "字符种类为: " << h_n <<"种"<< endl;
    cout << "字符总量为:" << h_sum << endl;
    cout << "(char,frequency):" << endl;
    int j = 0;
    for (int i = 1; i <= h_n; i++)
    {
        j++;
        cout << " (" << h_c[i].c << "," << h_c[i].num << ")";
        if (j == 10) { cout << endl; j = 0; }
    }
    cout << endl;
    fin.close();
}
void CHuffman::OutputCode()
{
    int j = 0;
    for (int i = 0; i < h_n; i++)
    {
        j++;
        h_c[i + 1].len = printCode(h_t[i]);
        if (j == 10) { cout << endl; j = 0; }
    }
    cout << endl;
}
void CHuffman::OutputInformation()
{
    float lv(0);
    for (int i = 1; i <= h_n; i++)
    {
        lv = lv + float(h_c[i].num)*h_c[i].len / h_sum;
    }
    cout << "平均哈夫曼编码长度为:" << lv << endl;
}

int main(void)
{
    char c[] = "C:/Users/86184/Desktop/test.txt";
    CHuffman  hm(c);
    hm.XCode();
    cout << endl;
    cout << "以下是哈夫曼编码:" << endl;
    hm.OutputCode();
    cout << endl;
    cout << "以下是哈夫曼编码的信息:" << endl;
    hm.OutputInformation();

}
