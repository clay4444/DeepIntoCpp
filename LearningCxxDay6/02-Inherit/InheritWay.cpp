#include<iostream>
using namespace std;

/**
 * 02-继承方式： public protected private
 */

/////////////////   公共继承  ////////////////
class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son1 :public Base1
{
public:

    void func()
    {
        m_A = 100; //父类中 公共权限 子类中变为  公共权限
        m_B = 100; //父类中 保护权限 子类中变为  保护权限
        //m_C = 100;// 父类中私有成员，子类无法访问
    }
};

void test01()
{
    Son1 s1;
    s1.m_A = 100; //在Son1中 m_A是公共权限  类外可以访问
    //s1.m_B = 100; //在Son1中 m_B是保护权限  类外不可以访问
}


/////////////////   保护继承  ////////////////
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class Son2 : protected Base2
{
public:
    void func()
    {
        m_A = 100;//父类中 公共权限 子类中变为  保护权限
        m_B = 100;//父类中 保护权限 子类中变为  保护权限
        //m_C = 100;//父类中私有成员，子类无法访问
    }
};

void test02()
{
    Son2 s;
    //s.m_A = 100;  //子类中 保护权限 无法访问
    //s.m_B = 100;  //子类中 保护权限 无法访问
    //s.m_C = 100; //子类本身没有访问权限
}


/////////////////   私有继承  ////////////////
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};
class Son3 :private Base3
{
public:
    void func()
    {
        m_A = 100;  //父类中 公共权限 子类中变为  私有权限
        m_B = 100;  //父类中 保护权限 子类中变为  私有权限
        //m_C = 100;//父类中私有成员，子类无法访问
    }
};
class GrandSon3 :public Son3
{
public:
    void func()
    {
        //m_A = 100;   //在Son3中 已经变为私有权限，GrandSon3访问不到
        //m_B = 100;
    }
};
void test03()
{
    Son3 s;
    //s.m_A = 100;//在Son3中变为私有权限，类外访问不到
    //s.m_B = 100;//在Son3中变为私有权限，类外访问不到
}


int main(){
    return EXIT_SUCCESS;
}