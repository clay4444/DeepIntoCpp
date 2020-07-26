#include<iostream>
using namespace std;

/**
 * 02  类模板中成员函数创建时机
 */


class Person1
{
public:
    void showPerson1()
    {
        cout << "Person1 show 调用" << endl;
    }
};

class Person2
{
public:
    void showPerson2()
    {
        cout << "Person2 show 调用" << endl;
    }
};


//类模板中的成员函数  并不是一开始创建的，而是在运行阶段确定出T的数据类型才去创建!
template<class T>
class MyClass
{
public:
    void func1()
    {
        obj.showPerson1();
    }
    void func2()
    {
        obj.showPerson2();
    }

    T obj;
};

void test01()
{
    MyClass <Person2> p1;
    //p1.func1();
    p1.func2();
}

int main(){
    test01();

    return EXIT_SUCCESS;
}