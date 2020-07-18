#include<iostream>
using namespace std;

/**
 * 06-继承中的静态成员处理！
 */

class Base
{
public:

    static void func()
    {
        cout << "Base中的func调用 " << endl;
    }

    static void func(int a)
    {
        cout << "Base中的func(int a)调用 " << endl;
    }

    static int m_A;

};

//静态成员：类内声明，类外初始化！
int Base::m_A = 10;


class Son :public Base
{
public:

    static void func()
    {
        cout << "Son中的func调用 " << endl;
    }

    static int m_A;
};
int Son::m_A = 20;

void test01()
{
    //1、通过对象访问
    Son s;
    cout << "m_A = " << s.m_A << endl;
    cout << "Base中的m_A = " << s.Base::m_A << endl;

    //2、通过类名访问

    cout << "m_A = " << Son::m_A << endl;
    //通过类名的方式 访问 父类作用域下的m_A静态成员变量
    cout << "Base中的m_A = " <<  Son::Base::m_A << endl;
}


void test02()
{
    //1、通过对象
    Son s;
    s.func();
    s.Base::func();

    //2、通过类名
    Son::func();
    //当子类重定义父类中同名成员函数，子类的成员函数会隐藏掉父类中所有版本，需要加作用域调用
    Son::Base::func(1);
}

int main() {
    //test01();
    test02();

    return EXIT_SUCCESS;
}