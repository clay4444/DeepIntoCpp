#pragma  once
#include<iostream>
using namespace std;

class MyString
{
    //左移运算符友元
    friend ostream& operator<<(ostream & cout, MyString & str);
    //右移运算符友元
    friend istream&  operator>>(istream & cin, MyString & str);
public:

    //有参构造
    MyString(char  * str);
    //拷贝构造
    MyString(const MyString & str);

    //重载=运算符

    MyString& operator=(const char * str);
    MyString& operator=(const MyString & str);

    //重载[]运算符
    char& operator[](int index);

    //重载+运算符
    MyString operator+(const char * str);
    MyString operator+(const MyString&str);

    //重载==运算符
    bool operator==(const char *str);
    bool operator==(const MyString &str);

    //析构
    ~MyString();

private:
    char * pString; //维护在堆区开辟的字符数组

    int m_Size; //字符串长度 不统计\0
};