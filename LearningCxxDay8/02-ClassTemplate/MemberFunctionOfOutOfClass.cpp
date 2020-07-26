#include<iostream>
using namespace std;
#include <string>

/**
 * 05  类模板中的成员函数类外实现
 */

template<class T1,class T2>
class Person
{
public:
    Person(T1 name, T2 age);  //类内定义！
    //{
    //	this->m_Name = name;
    //	this->m_Age = age;
    //}

    void showPerson();
    //{
    //	cout << "姓名： " << this->m_Name << " 年龄：" << this->m_Age << endl;
    //}

    T1 m_Name;
    T2 m_Age;
};

/**
 * 类外实现！   固定写法，记住就可以！
 */
template<class T1,class T2>
Person<T1,T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "姓名： " << this->m_Name << " 年龄：" << this->m_Age << endl;
}

void test01()
{
    Person <string, int>p("Tom", 10);
    p.showPerson();
}

int main(){
    test01();

    return EXIT_SUCCESS;
}