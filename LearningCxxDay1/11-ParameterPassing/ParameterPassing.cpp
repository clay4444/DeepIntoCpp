#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//1、值传递
void mySwap01(int a  , int b)
{
    int temp = a;
    a = b;
    b = temp;

    /*cout << ":::a = " << a << endl;
    cout << ":::b = " << b << endl;*/
}

//2、地址传递
void mySwap02(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//3、引用传递, 也可以实现交换
void mySwap03(int &a , int &b) // int &a = a; int &b = b;
{
    int temp = a;
    a = b;
    b = temp;
}

void test01()
{
    int a = 10;
    int b = 20;
    //mySwap01(a, b);
    //mySwap02(&a, &b);

    mySwap03(a, b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 返回一个引用
int& func()
{
    int a = 10;
    return a;
}

//引用注意事项
void test02()
{
    //1、引用必须引一块合法内存空间
    //int &a = 10;  //10是常量

    //2、不要返回局部变量的引用，局部变量在栈中！
    int &ref = func();
    cout << "ref = " << ref << endl;   //10
    cout << "ref = " << ref << endl;   //10
}

int& func2()
{
    static int a = 10;   //static 程序执行生命周期内一直存在！
    return a;
}

void test03()
{
    int &ref = func2();
    cout << "ref = " << ref << endl;   //10
    cout << "ref = " << ref << endl;   //10
    cout << "ref = " << ref << endl;   //10
    cout << "ref = " << ref << endl;   //10
    //当函数返回值是引用，那么函数的调用可以作为左值!
    func2() = 1000;

    cout << "ref = " << ref << endl;  //1000
}

int main(){
    //test01();
    //test02();
    test03();

    return EXIT_SUCCESS;
}