#include<iostream>
using namespace std;
#include <string>    //注意引入string库

//尽量使用const替代#define；  1：没有数据类型 2：不重视作用域

//1、对const变量取地址，会分配临时内存，好像没啥用
void test01()
{
    const int a = 10;
    int * p = (int *)&a;
}

//2、使用普通变量  初始化const变量，此时const的值就不是放在符号表中了，就可以被间接修改成功了
void test02()
{
    int a = 10;
    const int b = a; //使用普通变量  初始化const变量，此时const的值就不是放在符号表中了

    int *p = (int *)&b;
    *p = 1000;

    cout << "b = " << b << endl;  //1000  修改成功
}

//3、对于自定义数据类型被const修饰，也是可以被间接修改的
struct Person
{
    string m_Name;
    int m_Age;
};

void test03()
{
    const Person p{};
    //p.m_Age = 10;

    Person * pp = (Person *)&p;
    (*pp).m_Name = "Tom";
    pp->m_Age = 10;

    cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl; //间接修改成功
}

int main(){

    //test02();
    test03();
    return EXIT_SUCCESS;
}