#include "myString.h"

//重载左移运算符
ostream& operator<<(ostream & cout , MyString & str)
{
    cout << str.pString;
    return cout;
}

/**
 * 从用户终端接收输入，放入str中！
 */
istream& operator>>(istream & cin, MyString & str)
{
    //先清空原来堆区数据
    if (str.pString)
    {
        delete[] str.pString;
        str.pString = NULL;
    }

    char buf[1024];//开辟临时数组 记录用户输入内容
    cin >> buf;

    str.pString = new char[strlen(buf) + 1];
    strcpy(str.pString, buf);
    str.m_Size = strlen(buf);

    return cin;
}

MyString::MyString(char * str)
{
    //cout << "MyString有参构造函数调用" << endl;
    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
}

MyString::MyString(const MyString & str)
{
    //cout << "拷贝构造函数调用" << endl;
    this->pString =  new char[strlen(str.pString)+1];
    strcpy(this->pString, str.pString);
    this->m_Size = str.m_Size;
}

MyString& MyString::operator=(const char * str)
{
    //先判断原来堆区是否有内容，如果有先释放
    if (this->pString != NULL)
    {
        delete[]this->pString;
        this->pString = NULL;
    }

    this->pString = new char[strlen(str) + 1];
    strcpy(this->pString, str);
    this->m_Size = strlen(str);
    return *this;
}

MyString& MyString::operator=(const MyString & str)
{
    if (this->pString != NULL)
    {
        delete[]this->pString;
        this->pString = NULL;
    }

    this->pString = new char[strlen(str.pString) + 1];
    strcpy(this->pString, str.pString);
    this->m_Size = strlen(str.pString);
    return *this;
}

char& MyString::operator[](int index)
{
    return this->pString[index];
}

/**
 * +号运算符重载！
 */
MyString MyString::operator+(const char * str)
{
    //本身 abc   传入 def
    //计算开辟内存大小
    int newSize = this->m_Size + strlen(str) + 1;

    char * temp = new char[newSize];
    memset(temp, 0, newSize);

    strcat(temp, this->pString);  //字符串拼接
    strcat(temp, str);

    MyString newString = temp;  //相当于调用了有参构造！

    delete[] temp;  //需要清空堆区内存！

    return newString;
}

MyString MyString::operator+(const MyString&str)
{
    int newSize = this->m_Size + strlen(str.pString) + 1;

    char * temp = new char[newSize];
    memset(temp, 0, newSize);

    strcat(temp, this->pString);
    strcat(temp, str.pString);

    MyString newString = temp;

    delete[] temp;

    return newString;
}

bool MyString::operator==(const char *str)
{
    if ( strcmp( this->pString , str) == 0 )
    {
        return true;
    }
    return false;
}

bool MyString::operator==(const MyString &str)
{
    if (strcmp(this->pString, str.pString) == 0)
    {
        return true;
    }
    return false;
}

MyString::~MyString()
{
    if (this->pString != NULL)
    {
        //cout << "析构调用" << endl;
        delete[] this->pString;
        this->pString = NULL;
    }

}
