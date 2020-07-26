#include<iostream>
using namespace std;
#include <string>
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;

};

//显示两个变量 对比 函数
template<class T>
bool myCompare(T &a ,T&b)
{
    if (a == b)
    {
        return true;
    }
    return false;
}

//利用具体化技术 实现对自定义数据类型 提供特殊模板
//这不就相当于重新定义了一个函数嘛；
template<> bool myCompare(Person &a, Person &b)
{
    if (a.m_Name == b.m_Name && a.m_Age == b.m_Age)
    {
        return true;
    }
    return false;
}

void test01()
{
    //int a = 10;
    //int b = 10;

    //bool ret = myCompare(a, b);

    //if (ret )
    //{
    //	cout << "a == b" << endl;
    //}
    //else
    //{
    //	cout << "a != b" << endl;
    //}

    Person p1("Tom", 19);
    Person p2("Tom", 19);

    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2" << endl;
    }
    else
    {
        cout << "p1 != p2" << endl;
    }
}

int main(){
    test01();

    return EXIT_SUCCESS;
}