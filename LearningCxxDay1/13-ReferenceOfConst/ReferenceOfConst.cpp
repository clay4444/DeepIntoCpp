#include<iostream>
using namespace std;

void test01()
{
    //int &ref = 10;  //不可以

    //也就是说相当于在栈中创建了一个临时变量，ref指向了临时变量，这也就解释了为什么通过指针可以间接修改！
    const int &ref = 10; // 加了const之后，  相当于写成   int temp = 10;  const int &ref = temp;

    int *p = (int *)&ref;
    *p = 10000;

    cout << ref << endl;
}

void showValue(const int &a)
{
    //a = 100000;  //被const修饰后，这种修改会直接报错！
    cout << "a = " << a << endl;
}

//常量引用的一般使用场景 修饰函数中的形参，防止误操作！
void test02()
{
    int a = 100;
    showValue(a);
}

int main(){

    //test01();
    test02();
    return EXIT_SUCCESS;
}