#include<iostream>
using namespace std;
#include <list>
#include <algorithm>
#include <string>

/**
 * List： cxx里list就是双向链表！    不会造成空间浪费！
 * 对于任何位置的插入和删除，list永远是常数时间！
 * 没有跳跃访问的能力；
 * 插入和删除，都不会都不会造成原有list迭代器的失效！ 但是如果是删除，会让被删除元素的迭代器失效！
 */



/*
3.6.4.1 list构造函数
list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
list(beg,end);//构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem);//构造函数将n个elem拷贝给本身。
list(const list &lst);//拷贝构造函数。
3.6.4.2 list数据元素插入和删除操作
push_back(elem);//在容器尾部加入一个元素
pop_back();//删除容器中最后一个元素
push_front(elem);//在容器开头插入一个元素
pop_front();//从容器开头移除第一个元素
insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
clear();//移除容器的所有数据
erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos);//删除pos位置的数据，返回下一个数据的位置。
remove(elem);//删除容器中所有与elem值匹配的元素。
*/

//遍历链表
void printList(const list<int> & L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);

    //正序遍历
    //for (list<int>::iterator it = L1.begin(); it != L1.end();it++)
    //{
    //	cout << *it << endl;
    //}
    //逆序遍历
    for (list<int>::reverse_iterator it = L1.rbegin(); it != L1.rend();it++)
    {
        cout << *it << endl;
    }

    //list迭代器是不是支持随机访问 ,答案：不支持！  是一个双向迭代器
    list<int>::iterator itBegin = L1.begin();
    //itBegin = itBegin + 1;
}

void test03()
{
    list<int>L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    printList(L);

    L.pop_back(); //尾删
    L.pop_front(); //头删
    // 200 100 10 20
    printList(L);


    //插入
    L.insert(L.begin(), 10000);
    // 10000 200 100 10 20
    printList(L);

    L.erase(L.begin());
    // 200 100 10 20
    printList(L);

    //remove 删除容器中所有与elem值匹配的元素！
    L.push_back(100);
    L.push_back(100);
    L.remove(100);
    printList(L);

}

/*
3.6.4.3 list大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(num);//重新指定容器的长度为num，
若容器变长，则以默认值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。
resize(num, elem);//重新指定容器的长度为num，
若容器变长，则以elem值填充新位置。
如果容器变短，则末尾超出容器长度的元素被删除。

3.6.4.4 list赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
list& operator=(const list &lst);//重载等号操作符
swap(lst);//将lst与本身的元素互换。
3.6.4.5 list数据的存取
front();//返回第一个元素。
back();//返回最后一个元素。
*/
void test04()
{
    list<int>L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    list<int>L2;
    L2.assign(10, 100);

    L.swap(L2);

    printList(L);

}


/*
3.6.4.6 list反转排序
reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
sort(); //list排序
*/
bool myCompare(int v1 ,int v2)
{
    return v1 > v2;
}

void test05()
{
    list<int>L;
    L.push_back(10);
    L.push_back(20);
    L.push_back(30);
    L.push_front(100);
    L.push_front(200);
    L.push_front(300);

    //反转
    L.reverse();

    printList(L);

    //排序
    //如果容器的迭代器支持随机访问，可以使用系统提供的标准算法
    //不支持随机访问的迭代器的容器，内部会提供对应的算法接口
    //sort(L.begin(), L.end());
    L.sort(myCompare);
    printList(L);
}


class Person
{
public:
    Person(string name, int age , int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    bool operator==( const Person & p ) const
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age && this->m_Height == p.m_Height)
        {
            return true;
        }
        return false;
    }

    string m_Name;
    int m_Age;
    int m_Height;
};

bool myComparePerson( Person &p1, Person &p2)
{
    if (p1.m_Age == p2.m_Age )
    {
        return p1.m_Height < p2.m_Height;
    }

    return  p1.m_Age > p2.m_Age;
}

void test06()
{
    list<Person> L;

    Person p1("亚瑟", 40 ,  180);
    Person p2("赵云", 20 , 160);
    Person p3("妲己", 30 , 120);
    Person p4("孙悟空", 50 , 200);
    Person p5("关羽", 10 ,  170 );
    Person p6("刘备", 10  , 165);
    Person p7("张飞", 10 , 185);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);
    L.push_back(p7);

    //按照年龄进行降序   从大到下 , 如果年龄相等，按照身高进行升序
    //对于自定义数据类型，必须要指定排序规则
    L.sort(myComparePerson);

    for (list<Person>::iterator it = L.begin(); it != L.end();it++)
    {
        cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： "<< it->m_Height <<endl;
    }

    //删除孙悟空
    L.remove(p4);

    cout << "删除孙悟空后：" << endl;
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名： " << (*it).m_Name << " 年龄： " << it->m_Age << " 身高： " << it->m_Height << endl;
    }
}

int main(){
    //test02();
    //test03();
    //test04();
    //test05();
    test06();

    return EXIT_SUCCESS;
}