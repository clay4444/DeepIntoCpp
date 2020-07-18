#include<iostream>
#include <string>
using namespace std;

class MyPrint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};

void MyPrint2(string str)
{
    cout << str << endl;
}

void test01()
{
    MyPrint myPrint;
    myPrint("hello world"); // 也叫仿函数  本质是一个对象   所以也叫函数对象

    MyPrint2("hello world"); //普通函数
}

class MyAdd
{
public:
    int operator()(int a,int b)   //重载 () ：重载函数调用
    {
        return a + b;
    }
};

void test02()
{
    MyAdd myAdd;
    cout << myAdd(1, 1) << endl;

    //MyAdd()是一个匿名对象，当前执行完就销毁了，所以主要的作用就是如下：
    cout << MyAdd()(1, 1) << endl; // 匿名函数对象   特点：当前行执行完立即释放
}

int main() {
    //test01();
    test02();

    return EXIT_SUCCESS;
}