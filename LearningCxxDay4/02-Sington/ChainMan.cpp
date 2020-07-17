#include<iostream>
using namespace std;

//主席类
class ChairMan
{
public:
    static ChairMan * getInstacne()
    {
        return singleMan;
    }
private:
    //将构造函数私有化，不可以创建多个对象
    ChairMan(){};

    //默认拷贝构造函数可以克隆出一个新对象，所以要把拷贝构造函数覆盖
    ChairMan(const ChairMan &){};

//public:
private:
    //将主席指针 私有化，对外提供只读接口
    //因为如果是public的话，那么类外就可以修改了！
    static  ChairMan * singleMan;   //类内声明  类外初始化
};

//类内声明，类外初始化！
ChairMan *  ChairMan::singleMan = new ChairMan;

void test01()
{
    /*ChairMan c1;
    ChairMan c2;
    ChairMan * c3 = new ChairMan;*/

    //ChairMan * c1 = ChairMan::singleMan;
    //ChairMan * c2 = ChairMan::singleMan;

    //ChairMan::singleMan = NULL; //如果是public，这里就直接修改了；


    ChairMan * c1 = ChairMan::getInstacne();
    ChairMan * c2 = ChairMan::getInstacne();

    //ChairMan * c3 = new ChairMan(*c1);  //相当于克隆出来了一个新对象，所以要把拷贝构造函数覆盖

    if (c1 == c2)
    {
        cout << "c1 = c2" << endl;
    }
    else
    {
        cout << "c1 != c2" << endl;
    }

    //if (c1 == c3)
    //{
    //	cout << "c1 = c3" << endl;
    //}
    //else
    //{
    //	cout << "c1 != c3" << endl;
    //}
}

int main(){
    test01();

    return EXIT_SUCCESS;
}