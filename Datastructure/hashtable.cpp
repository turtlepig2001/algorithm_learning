#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
typedef struct infromationNode
{
    string phonenum;
    string name;
    string address;
    struct infromationNode *next;
} *Pointer;
int Hash(string phonenum)//hash函数
{
    int sum=0;
    for (int i = 0; i < 11; ++i)
    {
        sum+=phonenum[i];//11位数相加
    }
    int address=sum%7;//模7取余
    return address;//返回hash地址
}
Pointer Hashsearch(Pointer link_list[],string phonenum)
{
    int hashaddress;
    hashaddress=Hash(phonenum);
    Pointer p=link_list[hashaddress];
    while (p!=NULL&&p->phonenum!=phonenum)
    {
        p=p->next;
    }
    return p;
}
void Hashdelet(Pointer link_list[],string phonenum)
{
    int hashaddress=Hash(phonenum);
    Pointer s=link_list[hashaddress];
    if (s==NULL)
    {
        cout<<"此信息不存在"<<endl;
        return;
    }
    else
    {
        Pointer p=new infromationNode;//p为s的前一个结点
        p=NULL;
        while (s->phonenum!=phonenum&&s->next!=NULL)
        {
            p=s;
            s=s->next;
        }
        if (s->phonenum==phonenum)
        {
            if (p==NULL)//s即是链表中的第一个结点
            {
                link_list[hashaddress]=s->next;
            }
            else
            {
                p->next=s->next;
            }
            delete s;
            cout<<"联系人删除成功"<<endl;
        }
        else
            cout<<"此信息不存在"<<endl;
    }
}
void Hashinsert(Pointer link_list[],string phonenum)
{
    int hashaddress=Hash(phonenum);
    Pointer s=link_list[hashaddress];
    if (s==NULL)
    {
        Pointer information=new infromationNode;
        information->phonenum=phonenum;
        cout<<"请输入姓名信息"<<endl;
        string name;
        cin>>name;
        information->name=name;
        cout<<"请输入地址信息"<<endl;
        string address;
        cin>>address;
        information->address=address;
        information->next=NULL;
        link_list[hashaddress]=information;
        cout<<"新的联系人创建成功"<<endl;
    }
    else
    {
        while (s->phonenum!=phonenum&&s->next!=NULL)
        {
            s=s->next;
        }
        if (s->phonenum==phonenum)
        {
            cout<<"此信息已存在"<<endl;
            return;
        }
        else
        {
            Pointer information=new infromationNode;
            information->phonenum=phonenum;
            cout<<"请输入姓名信息"<<endl;
            string name;
            cin>>name;
            information->name=name;
            cout<<"请输入地址信息"<<endl;
            string address;
            cin>>address;
            information->address=address;
            information->next=NULL;
            cout<<"新的联系人创建成功"<<endl;
            s->next=information;
        }
    }
}
void creathashtable(Pointer link_list[])//读取数据文件建立hash表
{
    ifstream in;
    in.open("Phonenuminforamtion.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    string strOne;
    while (getline(in,strOne))
    {
        stringstream information;
        information<< strOne;
        string name;
        string phonenum;
        string address;
        information>>name>>phonenum>>address;
        Pointer q=new infromationNode;
        q->name=name;
        q->phonenum=phonenum;
        q->address=address;
        q->next=NULL;
        Pointer p=link_list[Hash(phonenum)];
        while (p->next!=NULL)
            p=p->next;
        p->next=q;
    }
    in.close();
}
void savedata(Pointer link_list[])//将hash表存入文件
{
    ofstream out;
    out.open("Phonenuminforamtion.txt", ios::trunc);
    if (!out.is_open())
    {
        cout<<"打开文件失败"<<endl;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        Pointer p = link_list[i];
        p=p->next;
        while (p!= NULL)
        {
            out<< p->name<< "\t" << p->phonenum<<"\t "<< p->address<<"\n";
            p=p->next;
        }
    }
    out.close();
}
void printhash(Pointer link_list[])//打印哈希表
{
    for (int i = 0; i < 8; i++)
    {
        Pointer p = link_list[i];
        p = p->next;
        while (p != NULL)
        {
            cout <<"姓名:"<<p->name<<",电话号码:"<< p->phonenum <<",地址:"<<p->address<<";"<<endl;
            p = p->next;
        }
    }
}
int main()
{
    Pointer link_list[8];
    for (int i = 0; i < 8; ++i)
    {
        Pointer p=new infromationNode;
        p->next=NULL;
        link_list[i]=p;
    }//初始化
    creathashtable(link_list);
    while (true)
    {
        meau:
        cout << "欢迎使用电话号码查询系统"<<endl;
        cout << "-------------------------" << endl;
        cout << "请输入您希望进行的操作"<<endl;
        cout << "1.打印哈希表" << endl;
        cout << "2.查找元素" << endl;
        cout << "3.插入元素" << endl;
        cout << "4.删除元素" << endl;
        cout << "5.退出系统并保存修改" << endl;
        cout << "6.退出系统不保存修改" << endl;
        cout << "-------------------------" << endl;
        int num;
        cin>>num;
        switch (num)
        {
            case 1:
            {
                printhash(link_list);
                break;
            }
            case 2:
            {
                cout<<"请输入要查找的电话号码"<<endl;
                string phonenum;
                cin>>phonenum;
                Pointer result=Hashsearch(link_list,phonenum);
                if (result==NULL)
                    cout<<"无效的电话号码，此号码不存在"<<endl;
                else
                {
                    cout <<"姓名:"<<result->name<<",电话号码:"<<result->phonenum <<",地址:"<<result->address<<";"<<endl;
                }
                break;
            }
            case 3:
            {
                cout<<"请输入要插入的电话号码"<<endl;
                string phonenum;
                cin>>phonenum;
                Hashinsert(link_list,phonenum);
                break;
            }
            case 4:
            {
                cout<<"请输入要删除的电话号码"<<endl;
                string phonenum;
                cin>>phonenum;
                Hashdelet(link_list,phonenum);
                break;
            }
            case 5:
            {
                savedata(link_list);
                cout<<"文件保存成功"<<endl;
                return 0;
            }
            case 6:
            {
                cout<<"成功退出，谢谢使用"<<endl;
                return 0;
            }
            default:cout<<"无效的输入，请重试"<<endl;
                goto meau;
        }
    }
}