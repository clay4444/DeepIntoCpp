#include<iostream>
using namespace std;

class Person
{
public:
    //1、静态成员变量
    //静态成员变量 ：编译阶段就分配了内存
    //类内声明 、类外初始化!
    //静态成员变量 所有对象都共享同一份数据
    static int m_A;

    //2、静态成员函数
    //所有对象都共享同一个func函数
    static void func()
    {
        //m_C = 100; //静态成员函数 不能访问非静态成员变量
        m_A = 100; //静态成员函数 能访问静态成员变量
        cout << "func调用" << endl;
    }

    int m_C;

private:
    static int m_B; //私有静态成员变量

    static void func2()
    {
    }
};

//类外初始化！
int Person::m_A = 0;
int Person::m_B = 0;


void test01()
{
    //1、通过对象进行访问
    Person p1;
    cout << p1.m_A << endl;

    Person p2;
    p2.m_A = 100;

    cout << p1.m_A << endl;  //100

    //2、通过类名进行访问, 因为是静态的！
    cout << Person::m_A << endl;

    //静态成员变量 也是有访问权限的，私有权限类外访问不到
    //cout << Person::m_B << endl;

}

/**
 * 静态方法的调用！
 */
void test02()
{
    //通过对象
    Person p1;
    p1.func();
    //通过类名
    Person::func();

    //Person::func2();  静态成员函数也是有访问权限的
}

int main(){

    //test01();
    test02();
    return EXIT_SUCCESS;
}