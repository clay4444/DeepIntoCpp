#include<iostream>
using namespace std;

//引用的本质：在c++内部实现其实就是一个指针 常量!

void testFunc(int& ref)  //发现是引用，转换为 int* const ref = &a;
{
    ref = 100;    //ref是引用，替换为 *ref是100
}

void referenceNature()
{
    int a = 10;
    int& aRef = a;  //自动转换为 int* const aRef = &a; 这也能说明为什么必须初始化, 因为被const修饰了，const修饰的变量必须创建时就初始化！
    aRef = 20;  //内部发现aRef是引用，自动转换为  *Ref = 20;
    cout << " a = " << a << endl;
    cout << " aRef = " << aRef << endl;
    testFunc(a);
}

//引用基本语法：  类型  &别名 = 原名
void test01()
{
    int a = 10;
    int &b = a;  //&放在右边表示取地址，放在左边表示引用

    b = 100;
    cout << "a = " << a << endl;  //100
    cout << "b = " << b << endl;  //100
}

void test02()
{
    int a = 10;
    //int &b; //引用必须定义时就要初始化

    int &b = a;

    //引用一旦初始化后，就不可以引向其他变量

    int c = 100;

    b = c; // 赋值

    cout << "a = " << a << endl;  //100
    cout << "b = " << b << endl;  //100
    cout << "c = " << c << endl;  //100
}

//对数组建立引用
void test03()
{
    //1、直接建立引用
    int arr[10];
    int(&pArr)[10] = arr;

    for (int i = 0; i < 10; i++)
    {
        arr[i] = 100 + i;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << pArr[i] << endl;
    }


    //2、先定义出数组类型，再通过类型 定义引用
    typedef int(ARRAY_TYPE)[10]; //定义了一个数组类型，共10个元素，每个元素的类型都是int类型
    //类型  &别名 = 原名
    ARRAY_TYPE & pArr2 = arr;

    for (int i = 0; i < 10; i++)
    {
        cout << pArr2[i] << endl;
    }
}

int main(){

    //test01();
    //test02();
    test03();

    return EXIT_SUCCESS;
}