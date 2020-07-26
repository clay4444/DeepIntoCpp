#include<iostream>
using namespace std;
#include <string>

/**
 * 07 类模板碰到友元函数
 */

/**
 * 第五步：第四步用到了Person，这里要先定义出来！
 */
template<class T1,class T2>
class Person;

/**
 * 第四步：如果是模板友元函数的话，需要先告诉编译器，这是一个模板！
 */
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p);

/**
 * 第三种写法：声明的时候就立即实现！ 也需要person提前定义
 */
template<class T1,class T2>
void printPerson3(Person<T1, T2>&p)
{
    cout << "类外实现 --- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

template<class T1, class T2>
class Person
{
    //1、友元函数 类内实现 [最简单，就用它吧], 其实这也是一个全局的友元函数! 只是位置放到了类内部！
    //其实也可以这样理解，友元函数就是为了访问某个类内部private属性的！ 所以即使放到类内部，作用域也是全局的！
    friend void printPerson(Person<T1, T2> &p)
    {
        cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
    }

    //2、友元函数 类外实现
    //很复杂， 不容易理解； //第一步：类内定义
    friend void printPerson2<>(Person<T1, T2> &p);  //所以第三步：<> 告诉编译器，这是一个模板函数！ 否则编译器会认为是一个普通函数；

    //3、第三种写法：声明的时候就立即实现！
    friend void printPerson3<>(Person<T1, T2> &p);
public:
    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

private:
    T1 m_Name;
    T2 m_Age;
};

//第二步：类外实现，类外定义时因为有T1，T2； 所以需要定义模板，template<class T1,class T2>
//此时的问题是类内定义的是一个普通函数，而这里定义的变成了模板函数，就会导致连接的时候，找类内部普通函数的实现，找不到，报连接错误！
template<class T1,class T2>
void printPerson2(Person<T1, T2> &p)
{
    cout << "类外实现 --- 姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
}

void test01()
{
    Person <string, int> p("Tom", 100);
    printPerson(p);
    printPerson2(p);
    printPerson3(p);
}

int main(){
    test01();

    return EXIT_SUCCESS;
}