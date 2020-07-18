#include<iostream>
using namespace std;

/**
 * 03-对象模型
 */

class Base
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;  //父类中私有属性，子类访问不到，是由编译器给隐藏了, 但是仍然是有的，只是访问不到！
};

class Son : public Base
{
public:
    int m_D;
};


void test01()
{
    //4  8    12   16
    cout << "size of  Son = " << sizeof(Son) << endl; // 结果为16

}


int main(){
    test01();

    return EXIT_SUCCESS;
}