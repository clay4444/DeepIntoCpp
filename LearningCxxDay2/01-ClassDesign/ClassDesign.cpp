#include<iostream>
using namespace std;
#include <string>

//设计一个类，求圆的周长

const double PI = 3.14;

//class + 类名
//周长公式 ：   2 * pi * m_R
class Circle
{
public: //公共权限

    //类中的函数  称为 成员函数  成员方法
    //求圆周长
    double calculateZC()
    {
        return 2 * PI * m_R;
    }

    //设置半径
    void setR(int r)
    {
        m_R = r;
    }

    //获取半径
    int getR()
    {
        return m_R;
    }


    //类中的变量   称为成员变量  成员属性
    //半径
    int m_R;

};

void test01()
{
    Circle  c1; //通过类 创建一个对象   实例化对象

    //给c1 半径赋值
    //c1.m_R = 10;
    c1.setR(10);


    //求c1圆周长
    cout << "圆的半径为： " << c1.getR() << endl;
    cout << "圆的周长为： " << c1.calculateZC() << endl;

}



//2 设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student
{
public:
    //设置姓名
    void setName(string name)
    {
        m_Name = name;
    }

    //设置学号
    void setId(int id)
    {
        m_Id = id;
    }

    //显示学生信息
    void showStudent()
    {
        cout << "姓名：" << m_Name << " 学号： " << m_Id << endl;
    }

    //属性：
    //姓名
    string m_Name;
    //学号
    int  m_Id;
};

void test02()
{
    Student s1;    //那这样看和java的区别就是不用new这个关键字了，直接分配空间！
    s1.m_Name = "张三";
    s1.m_Id = 1;

    cout << "姓名：" << s1.m_Name << " 学号： " << s1.m_Id << endl;

    Student s2;
    s2.setName("李四");
    s2.setId(2);
    s2.showStudent();

    Student s3;
    s3.setName("王五");
    s3.setId(3);
    s3.showStudent();
}

int main(){
    //test01();
    test02();

    return EXIT_SUCCESS;
}