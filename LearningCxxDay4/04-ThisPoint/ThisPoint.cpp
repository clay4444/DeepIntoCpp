#include<iostream>
using namespace std;

/**
 * this指针！
 */

class Person
{
public:
    Person(int age)
    {
        //用途1 ：解决名称冲突
        this->age = age;
    }

    //this指针 隐式加在每个成员函数中
    bool compareAge(Person &p)
    {
        if (this->age == p.age)
        {
            return true;
        }
        return false;
    }

    //用途2 ：链式编程
    //如果返回的是 Person，相当于是值返回，会调用拷贝构造函数，来创建一个新的对象      值返回=调用拷贝构造函数！
    Person&  personAddPerson(Person &p)
    {
        this->age += p.age;
        return *this; //*this 就是本体
    }

    int age;
};

void test01()
{
    //this指针 指向 被调用的成员函数 所属的对象！
    Person p1(10);

    cout << "p1的年龄为： " << p1.age << endl;

    Person p2(10);

    bool ret = p1.compareAge(p2);
    if (ret)
    {
        cout << "p1与p2年龄相等" << endl;
    }

    p1.personAddPerson(p2).personAddPerson(p2).personAddPerson(p2);     //链式编程
    cout << "p1的年龄为： " << p1.age << endl;
}

int main(){
    test01();

    return EXIT_SUCCESS;
}