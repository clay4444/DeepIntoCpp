#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置


find_if算法 条件查找
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return bool 查找返回true 否则false

*/



void test01()
{
    vector<int>v;
    for (int i = 0; i < 10;i++)
    {
        v.push_back(i);
    }

    vector<int>::iterator pos = find(v.begin(), v.end(), 5);

    if (pos != v.end())
    {
        cout << "找到了元素：" << *pos << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    bool operator==(const Person & p)  //重载==，因为find底层就是使用的==做的对比，相当于java中的equals()方法
    {
        return this->m_Name == p.m_Name && this->m_Age == p.m_Age;
    }

    string m_Name;
    int m_Age;
};

void test02()
{
    vector<Person> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);


    vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
    if (pos != v.end())
    {
        cout << "找到了元素  姓名： " << (*pos).m_Name << " 年龄： " << (*pos).m_Age << endl;
    }
}


class MyComparePerson :public binary_function< Person *, Person *, bool>
{
public:
    bool operator()(  Person * p1 ,  Person *p2 ) const
    {
        return p1->m_Name == p2->m_Name  && p1->m_Age == p2->m_Age;
    }
};

void test03()
{
    vector<Person *> v;

    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);

    v.push_back(&p1);  //存的是指针；
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);

    Person * p = new Person("bbb", 20);

    vector<Person *>::iterator pos = find_if(v.begin(), v.end(), bind2nd( MyComparePerson() ,p)  );   //适配器！

    if (pos != v.end())
    {
        cout << "找到了元素--- 姓名： " << (*pos)->m_Name << " 年龄： " << (*pos)->m_Age << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}


//adjacent_find算法 查找相邻重复元素
void test04()
{
    vector<int>v;

    v.push_back(3);
    v.push_back(2);
    v.push_back(300);
    v.push_back(300);
    v.push_back(6);
    v.push_back(3);

    vector<int>::iterator ret = adjacent_find(v.begin(), v.end());

    if (ret != v.end())
    {
        cout << "找到了相邻的重复元素： " << *ret << endl;
    }
    else
    {
        cout << "未找到" << endl;
    }
}


/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
*/

void test05()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    //v.push_back(4);  必须是有序序列，如果无效 结果未知

    bool ret=binary_search(v.begin(), v.end(), 2);
    if (ret)
    {
        cout << "查到了数据2" << endl;
    }
    else
    {
        cout << "未找到数据2" << endl;
    }

}

/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/
class GreaterThan3
{
public:
    bool operator()(int val)
    {
        return val >= 3;
    }
};

void test06()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    v.push_back(3);
    v.push_back(3);
    v.push_back(3);

    int num = count(v.begin(), v.end(), 3);

    cout << "3的个数为： " << num << endl;


    //统计大于等于3的个数
    num = count_if(v.begin(), v.end(), GreaterThan3());
    // 0 1 2 3 4 5 6 7 8 9 3 3 3
    cout << "大于等于3的个数为： " << num << endl;

}


int main(){
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();

    return EXIT_SUCCESS;
}