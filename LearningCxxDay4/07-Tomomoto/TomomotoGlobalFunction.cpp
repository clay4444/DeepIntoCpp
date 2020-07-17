#include<iostream>
#include <string>
using namespace std;

/**
 * 全局函数作为友元函数！
 */

class Building
{
    //利用friend关键字让全局函数  goodGay作为本类好朋友，可以访问私有成员
    friend void goodGay(Building * buliding);

public:
    Building()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }

public:
    string m_SittingRoom; //客厅
private:
    string m_BedRoom; //卧室
};

//好基友全局函数  可以访问Building的私有属性
void goodGay( Building * buliding)
{
    cout << "好基友正在访问：" << buliding->m_SittingRoom << endl;

    cout << "好基友正在访问：" << buliding->m_BedRoom << endl;  //这里，访问到了私有变量！
}

void test01()
{
    Building buliding;   //这里就会调用默认构造函数！  new是放在堆里！  和java一个非常不同的地方！
    goodGay(&buliding);
}

int main(){
    test01();

    return EXIT_SUCCESS;
}