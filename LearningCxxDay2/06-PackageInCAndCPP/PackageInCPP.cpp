#include<iostream>
using namespace std;

struct  Person
{
    //公共权限
public:
    char name[64];
    int age;

    void PersonEat()
    {
        printf("%s在吃人饭\n", name);
    }
};

struct Dog
{
    //公共权限
public:
    char name[64];
    int age;

    void DogEat()
    {
        printf("%s在吃狗粮\n", name);
    }
};

//C++封装 理念：  将属性和行为作为一个整体，来表现生活中的事物

//第二次理念： 将属性和行为  加以权限控制

void test01()
{
    struct Person p;
    strcpy(p.name, "老王");

    p.PersonEat();

    //p.DogEat();
}


//struct和class 区别？
//class 默认权限  私有权限  而 struct默认权限是 公共权限
//访问权限
// public  公共权限    成员 类内  类外 都可以访问
// private 私有权限    成员 类内  可以访问  类外  不可以访问  儿子不可以访问父亲的private权限内容
// protected 保护权限  成员 类内  可以访问  类外  不可以访问  儿子可以访问父亲的protected权限内容

class Person2
{
public:
    string m_Name; //公共权限

protected:
    string m_Car;  //保护权限

private:
    int  m_pwd;  //私有权限

public:

    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_pwd = 123456;
    }

};

void test02()
{
    Person2 p;
    p.m_Name = "李四"; //公共权限  类外可以访问
//	p.m_Car = "劳斯莱斯"; //保护权限  类外访问不到
//	p.m_pwd = 123; //私有权限  类外不可以访问
}

int main(){
    test01();

    return EXIT_SUCCESS;
}