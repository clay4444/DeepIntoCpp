#include<iostream>
using namespace std;
#include "myArray.hpp"
#include <string>

class Person
{
public:
    Person(){};
    Person(string name,int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    string m_Name;
    int m_Age;
};

void myPrintInt(MyArray <int> &myIntArr)
{

    for (int i = 0; i < myIntArr.getSize();i++)
    {
        cout << myIntArr[i] << endl;
    }
}

void test01()
{
    MyArray <int> myIntArr(100);
    for (int i = 0; i < 10;i++)
    {
        myIntArr.pushBack(i + 100);
    }
    myPrintInt(myIntArr);

}

void myPrintPerson(MyArray<Person> &myPersonArr)
{
    for (int i = 0; i < myPersonArr.getSize();i++)
    {
        cout << "姓名" << myPersonArr[i].m_Name << "年龄" << myPersonArr[i].m_Age << endl;
    }
}

void test02()
{
    MyArray<Person> myPersonArr(100);
    Person p1("姓名1", 1000);
    Person p2("姓名2", 800);
    Person p3("姓名3", 500);
    Person p4("姓名4", 300);
    Person p5("姓名5", 10000);

    myPersonArr.pushBack(p1);
    myPersonArr.pushBack(p2);
    myPersonArr.pushBack(p3);
    myPersonArr.pushBack(p4);
    myPersonArr.pushBack(p5);

    myPrintPerson(myPersonArr);

    cout << "容量" << myPersonArr.getCapacity() << endl;
    cout << "大小" << myPersonArr.getSize() << endl;
}

int main(){
//	test01();
    test02();

    return EXIT_SUCCESS;
}