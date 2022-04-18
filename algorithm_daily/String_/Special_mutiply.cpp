#include <iostream>
#include <string>
using namespace std;

int main()
{
    string num1,num2;
    cin>> num1;
    cin>> num2;
    long long sum = 0;
    int temp1,temp2;
    for(int i=0;i<num1.size();i++)
    {
        temp1=num1[i]-'0';
        for (int j=0;j<num2.size();j++)
        {
            temp2=num2[j]-'0';
            sum+=(int)temp1*(int)temp2;//这里不加int也行
        }
    }
    cout<<sum<<endl;
    return 0;
}

/*
总计：c++中字符按ASCII码保存，必须要减去‘0’ASCII码才能再将其转换为整数，否则直接将会直接把ASCII当作整形数字
*/