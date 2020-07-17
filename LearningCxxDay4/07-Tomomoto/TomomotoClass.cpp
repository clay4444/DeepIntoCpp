#include<iostream>
#include <string>
using namespace std;

/**
 * 类作为友元类！
 */

class Building;
class GoodGay
{
public:
    GoodGay();  //还可以这样写， 相当于这里只是预定义！
    void visit();
    Building * m_building;
};

class Building
{
    //让goodGay类作为 Building的好朋友，可以访问私有成员
    friend class GoodGay;

public:
    Building();  //这里也是预定义，在下边具体实现！

    string m_SittingRoom;

private:
    string m_BedRoom;
};


Building::Building()  //然后在类外边去实现！
{
    this->m_SittingRoom = "客厅";
    this->m_BedRoom = "卧室";
}

GoodGay::GoodGay()   //然后在类外边去实现！
{
    this->m_building =  new Building;
}

void GoodGay::visit()    //然后在类外边去实现！
{
    cout << "好基友正在访问： " << this->m_building->m_SittingRoom << endl;
    cout << "好基友正在访问： " << this->m_building->m_BedRoom << endl;
}

void test01()
{
    GoodGay gg;   //调用默认构造器，给this的m_building舒心赋值！
    gg.visit();
}

int main() {
    test01();

    return EXIT_SUCCESS;
}