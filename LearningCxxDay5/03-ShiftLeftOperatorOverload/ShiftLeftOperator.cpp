#include<iostream>
using namespace std;

/**
 * 左移运算符重载，相当于java中的 toString() 方法！
 */

class Person
{
    //友元函数
    friend ostream& operator<<(ostream &cout, Person & p1);
public:
    Person(int a, int b)
    {
        this->m_A = a;
        this->m_B = b;
    }

    //试图利用成员函数 做<<重载， 不可以，因为实际用的时候，cout是在方法调用左边的， 使用成员函数只能做到cout在函数调用右边！
    //void operator<<( Person & p)    // p.operator<<(cout)    p<<cout
    //{
    //
    //}

private:    //作用域是private
    int m_A;
    int m_B;
};

/**
 * 利用全局函数 实现左移运算符重载， 相当于java中重写 toString() 方法！
 * @return ostream& 而不是 void 的原因是实际打印时，后面还会继续调用 << 运算符打印换行！
 */
ostream& operator<<(ostream &cout, Person & p1)
{
    cout << "m_A = " << p1.m_A << " m_B = " << p1.m_B;
    return cout;
}

void test01()
{
    Person p1(10, 10);
    cout << p1 << endl;
}

int main(){
    test01();

    return EXIT_SUCCESS;
}