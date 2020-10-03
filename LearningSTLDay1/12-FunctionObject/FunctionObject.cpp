#include<iostream>
using namespace std;

class MyPrint
{
public:
    void operator()(int num)
    {
        cout << num << endl;
        m_Count++;
    }

    int m_Count = 0;
};

void myPrint02(int num)
{
    cout << num << endl;
}

void test01()
{
    MyPrint myPrint;
    myPrint(100); //本质是一个类的对象，因此称为函数对象，也叫仿函数

    myPrint02(100);
}


void test02()
{
    //函数对象 超出了普通函数的概念，可以拥有自己状态

    MyPrint myPrint;
    myPrint(100);
    myPrint(100);
    myPrint(100);
    myPrint(100);

    cout << "调用次数为： " << myPrint.m_Count << endl;
}


//函数对象可以作为函数参数!!
void doPrint(MyPrint myPrint , int num)
{
    myPrint(num);
}

void test03()
{
    doPrint(MyPrint(), 1000);
}

int main(){

    //test01();
    //test02();
    test03();

    return EXIT_SUCCESS;
}