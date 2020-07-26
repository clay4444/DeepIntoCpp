#include<iostream>
using namespace std;

//函数重载条件
//1、在同一个作用域
//2、函数名称相同
//3、参数个数、类型、顺序不同

//class Person
//{
//public:
//	void func()   成员函数 而不是全局函数
//	{
//	}
//};

void func()
{
    cout << "func()调用" << endl;
}

void func(int a)
{
    cout << "func(int a)调用" << endl;
}

void func(double a)
{
    cout << "func(double a)调用" << endl;
}

void func(int a, double b)
{
    cout << "func(int a ,double b)调用" << endl;
}

void func(double a, int b)
{
    cout << "func(double a, int b)调用" << endl;
}

//返回值可不可以作为函数重载的条件 答案：不可以
//int func(int a, double b)
//{
//	cout << "func(int a ,double b)调用" << endl;
//}



void test01()
{
    func(1,3.14);
}



//函数重载中 引用两个版本
//void myFunc(int a)
//{
//	cout << "myfunc(int a )调用" << endl;
//}

/**
 * 下面两个函数可以同时存在，原因：
 * 1. int a = 10; myFunc(a); 会调用第一个函数，因为此时a是一个变量；
 * 2. 如果直接myFunc(10) 会调用第二个函数，因为第一个函数 int & a = 10； a指向了不合法的地址；
 * 而const int &a = 10是合法的，这是常量引用，相当于创建了一个临时变量！   复习看第一天最后一节
 */
void myFunc(int &a) // int & a  = 10;         不会调用这个方法，因为a指向了一块不合法的地址空间
{
    cout << "myfunc(int &a )调用" << endl;
}
void myFunc(const int &a) // const int &a = 10;    加了const，相当于创建了一个临时变量！
{
    cout << "myfunc( const int &a )调用" << endl;
}


void test02()
{
    int a = 10;
    //myFunc(a);//需要避免二义性出现
}


//函数重载碰到默认参数  注意避免二义性出现
void func2(int a , int b = 10)
{

}

void func2(int a)
{

}

void test03()
{
    //func2(10); //出现二义性
}


int main(){
    //test01();
    test02();

    return EXIT_SUCCESS;
}