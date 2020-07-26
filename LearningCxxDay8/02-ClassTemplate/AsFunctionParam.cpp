#include<iostream>
using namespace std;
#include <string>

/**
 * 03 类模板作为函数参数！
 */

template<class T1, class T2>
class Person
{
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void showPerson()
    {
        cout << "姓名： " << this->m_Name << " 年龄： " << this->m_Age << endl;
    }
    T1 m_Name;
    T2 m_Age;
};

//1、指定传入类型
void doWork(Person <string, int>&p)
{
    p.showPerson();
}

void test01()
{
    Person <string, int>p("孙悟空", 999);
    doWork(p);
}


//2、参数模板化
template<class T1, class T2>
void doWork2(Person <T1, T2>&p)
{
    cout << "T1数据类型： " << typeid(T1).name() << endl;
    cout << "T2数据类型： " << typeid(T2).name() << endl;
    p.showPerson();
}

void test02()
{
    Person<string, int>p("猪八戒", 998);
    doWork2(p);
}


//3、整个类 模板化
template<class T>
void doWork3(T &p)
{
    cout << "T的数据类型： " << typeid(T).name() << endl;
    p.showPerson();
}

void test03()
{
    Person<string, int>p("唐僧", 10000);
    doWork3(p);
}

int main(){
    //test01();
    //test02();
    test03();

    return EXIT_SUCCESS;
}