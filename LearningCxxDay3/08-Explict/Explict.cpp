#include<iostream>
using namespace std;

class MyString
{
public:
    MyString(char * str)
    {

    }
    //explicit用途： 防止利用隐式类型转换方式来构造对象
    explicit MyString(int len)
    {

    }
};

void test01()
{
    MyString str1(10);

    MyString str2 = MyString(100);

    //MyString str3 = 10; // "10"
}

int main(){

    test01();

    return EXIT_SUCCESS;
}