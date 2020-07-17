#include<iostream>
using namespace std;

//===========================================================================
//                      构造函数的分类和调用！
//===========================================================================


//构造函数分类
//按照参数分类： 无参构造(默认构造函数) 和 有参构造
//按照类型分类： 普通构造函数    拷贝构造函数
class Person
{
public:

    //无参构造(默认构造函数) 和 有参构造
    Person()
    {
        cout << "Person的默认构造函数调用" << endl;
    }

    Person(int age)
    {
        m_Age = age;
        cout << "Person的有参构造函数调用" << endl;
    }

    //拷贝构造函数
    Person(const Person &p )
    {
        cout << "Person的拷贝构造函数调用" << endl;
        m_Age = p.m_Age;
    }

    //析构函数
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }

    int m_Age;

};

//构造函数的调用
void test01()
{
    //Person p;

    //1、括号法
    //Person p1(10);    //这种就相当于java中调用了new
    //Person p2(p);

    //注意事项一
    //不要用括号法 调用无参构造函数  Person p3();  编译器认为代码是函数的声明

    //2、显示法
    //Person p3 = Person(10);   //有参构造
    //Person p4 = Person(p3);   //拷贝构造

    //Person(10); //匿名对象  特点： 当前代码行执行完后 立即释放

    //cout << "aaa" << endl;

    //注意事项二
    //不要用拷贝构造函数 初始化 匿名对象 Person(p3); 编译器认为 Person p3对象实例化  如果已经有p3  p3就重定义

    //3、隐式法
    Person p5 = 10; //Person p5 = Person(10);
    Person p6 = p5;
}

int main(){
    test01();
    //Person p(18);
    //Person p2(p);
    //cout << "p2的年龄： " << p2.m_Age << endl;

    return EXIT_SUCCESS;
}