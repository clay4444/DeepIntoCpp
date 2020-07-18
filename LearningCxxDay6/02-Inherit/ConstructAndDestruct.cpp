#include<iostream>
using namespace std;

/**
 * 04-继承中的构造和析构！
 */

class Base1
{
public:
    Base1()
    {
        cout << "Base1的构造函数调用" << endl;
    }

    ~Base1()
    {
        cout << "Base1的析构函数调用" << endl;
    }

};


class Other
{
public:
    Other()
    {
        cout << "Other的构造函数调用" << endl;
    }

    ~Other()
    {
        cout << "Other的析构函数调用" << endl;
    }
};

class Son1 :public Base1
{
public:
    Son1()
    {
        cout << "Son1的构造函数调用" << endl;
    }

    ~Son1()
    {
        cout << "Son1的析构函数调用" << endl;
    }

    Other other;
};



void test01()
{
    Son1 s; //先调用父类构造，再调用其他成员构造， 再调用自身构造 ，析构的顺序与构造相反

}


class Base2
{
public:
    Base2(int a)
    {
        this->m_A = a;
        cout << "Base2的构造函数调用" << endl;
    }
    int m_A;
};

class Son2 :public Base2
{
public:
    Son2(int a = 1000 ) :Base2(a)  //利用初始化列表语法  显示调用父类中的其他构造函数
    {
        cout << "Son2的构造函数调用" << endl;
    }
};
void test02()
{
    Son2 s;
    cout << s.m_A << endl;
}

//父类中 构造、析构、拷贝构造 、operator=  是不会被子类继承下去的

int main(){
    //test01();
    test02();

    return EXIT_SUCCESS;
}