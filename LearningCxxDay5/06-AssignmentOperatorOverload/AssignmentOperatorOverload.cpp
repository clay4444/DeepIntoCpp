#include<iostream>
using namespace std;

//编译器 默认给一个类4个函数   默认构造   析构   拷贝构造 （值拷贝）  operator= (值拷贝)
class Person
{
public:
    Person(char * name, int age)
    {
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
        this->m_Age = age;
    }

    /**
     * 重载 =
     * 原因：默认提供的 operator=函数也都是浅拷贝，也会和默认构造一样，造成堆区重复释放！
     * @return Person& 引用，目的：为了实现 p3 = p2 = p1;
     */
    Person& operator=( const Person &p)
    {
        //先判断原来堆区释放有内容，如果有先释放
        if (this->m_Name != NULL)
        {
            delete [] this->m_Name;
            this->m_Name = NULL;
        }

        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);
        this->m_Age = p.m_Age;
        return *this;
    }

    //拷贝构造
    Person(const Person & p)
    {
        this->m_Name = new char[strlen(p.m_Name) + 1];
        strcpy(this->m_Name, p.m_Name);
        this->m_Age = p.m_Age;
    }

    ~Person()
    {
        if (this->m_Name!=NULL)
        {
            delete [] this->m_Name;
            this->m_Name = NULL;
        }
    }

    char * m_Name;
    int m_Age;
};


void test01()
{
    Person p1("Tom",10);

    /**
     * 以下两种都是调用的拷贝构造函数！
     */
    //Person p2(p1);
    //Person p2 = p1;

    Person p2("Jerry",19);
    p2 = p1;   //这个才是赋值运算符！   最终的结果其实和默认拷贝构造函数一样，都是浅拷贝！

    Person p3("", 0);
    p3 = p2 = p1;

    Person p4 = p3;  //调用的拷贝构造函数！

    cout << "p1姓名： "<< p1.m_Name << "  p1年龄： " << p1.m_Age << endl;
    cout << "p2姓名： "<< p2.m_Name << "  p2年龄： " << p2.m_Age << endl;
    cout << "p3姓名： " << p3.m_Name << " p3年龄： " << p3.m_Age << endl;

}

int main(){
    test01();

    /*int a = 10;
    int b = 20;
    int c;
    c = a = b;    //等号运算符从右到左计算！
    cout << "a = " << a << " b = " << b << " c = " << c << endl; */    // 20  20   20

    return EXIT_SUCCESS;
}