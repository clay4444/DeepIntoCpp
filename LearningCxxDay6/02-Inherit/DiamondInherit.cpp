#include<iostream>
using namespace std;

/**
 *  08-菱形继承
 */

//动物类
class Animal
{
public:
    int m_Age;      //年龄
};

//Animal称为 虚基类

//羊类
class Sheep : virtual public Animal{};
//驼类
class Tuo : virtual public Animal{};

//羊驼
class SheepTuo : public Sheep, public Tuo
{
};

void test01()
{
    SheepTuo st;

    //问题：继承了两个m_Age；   解决办法： 虚继承 virtual关键字！
    st.Sheep::m_Age = 10;  //从羊继承的
    st.Tuo::m_Age = 20;  //从鸵继承的

    cout << "Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "Tuo::m_Age = " << st.Tuo::m_Age << endl;
    cout << "age = " << st.m_Age << endl;

    //当发生虚继承后，sheep和tuo类中 继承了一个vbptr指针（虚基类指针）指向的是一个 虚基类表 vbtable（sheep和tuo类中每个都有自己的虚基类表！）
    //虚基类表中记录了一个偏移量 ，通过这个偏移量就可以找到唯一的一个m_Age
    //所以也就是说，这四个类中，只有一份m_Age变量， sheep和tuo类中根本没有继承这个变量，只是创建了一个虚基类指针，来指向唯一的一份m_Age变量！
}

void test02()
{
    SheepTuo st;
    st.m_Age = 10;

    //通过Sheep找到 偏移量
    //*(int *)&st 解引用到了 虚基类表中
    cout << *((int *)*(int *)&st + 1) << endl;

    //通过Tuo 找到偏移量
    cout << *((int *)*((int *)&st + 1) + 1) << endl;

    //通过偏移量  访问m_Age
    cout << "m_Age = " << ((Animal *)((char *)&st + *((int *)*(int *)&st + 1)))->m_Age << endl;

    cout << "m_Age = " << *((int *)((char *)&st + *((int *)*(int *)&st + 1))) << endl;
}

int main() {
    test01();
    //test02();

    return EXIT_SUCCESS;
}