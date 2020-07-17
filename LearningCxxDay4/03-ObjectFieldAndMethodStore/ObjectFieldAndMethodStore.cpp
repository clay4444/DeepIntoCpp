#include<iostream>
using namespace std;

//#pragma pack(1)

class Person
{
public:

    int m_A; //只有非静态成员变量  属于类对象上

    void func( )  //成员函数  并不属于类对象上
    {

    }

    static int m_B; //静态成员变量  不属于类对象上

    static void func2()//静态成员函数  不属于类对象上
    {
    }

    double m_C;

};
int Person::m_B = 0;

void test01()
{
    //空类的sizeof结果是1  原因  每个对象都应该在内存上有独一无二的地址，因此给空对象分配1个字节空间
    // Person pArr[10]  pArr[0]  pArr[1]
    Person p1;
    //  空对象 大小 1
    cout << "sizeof = " << sizeof(p1) << endl;
}

int main(){
    test01();

    return EXIT_SUCCESS;
}