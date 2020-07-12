#include<iostream>
using namespace std;

//宏函数优势：空间换时间，只是源码层的替换，没有函数入栈出栈的开销！

//宏缺陷1 ： 必须要加括号保证运算完整
#define  MYADD(x,y)  ((x) +(y))
void test01()
{
    int a = 10;
    int b = 20;
    int ret = MYADD(a, b) * 20;
    cout << ret << endl;
}

//宏缺陷2：  即使加了括号，有些运算依然与预期不符
#define MYCOMPARE(a,b)  (((a) < (b)) ? (a) : (b))

//普通函数 不会出现与预期结果不符的问题
void myCompare(int a, int b)
{
    int ret = a < b ? a : b;
    cout << "ret = " << ret << endl;
}

void test02()
{
    int a = 10;
    int b = 20;

    myCompare(++a, b);
    //int ret = MYCOMPARE(++a, b); //预期是 11 结果变为12   (((++a) < (b)) ? (++a) : (b))    因为有两次++操作！
    //cout << "ret = " << ret << endl;
}

//内联函数
//函数的声明和实现必须同时加关键字 inline  才算内联函数
//内联函数 好处：解决宏缺陷！，本身是一个函数，带来宏优势，以空间换时间，在适当的时候做展开
inline void func();
inline void func(){};
//类内部的成员函数 在函数前都隐式加了关键字 inline，但也不是所有函数都会加,有一些要求
//1.不能存在循环语句
//2.不能存在过多的条件判断
//3.函数体不能太庞大
//4.不能对函数进行取址操作

//内联只是给编译器一个建议，编译器不一定接受这个建议，即使没有声明为内联函数，也有可能会优化为内联函数！

int main(){

    //test01();
    test02();
    return EXIT_SUCCESS;
}