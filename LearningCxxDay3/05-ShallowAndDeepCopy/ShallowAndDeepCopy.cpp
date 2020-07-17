#include<iostream>
using namespace std;

class Person
{
public:

    Person( char * name ,int age )
    {
        m_Name = (char *) malloc(strlen(name) + 1);

        strcpy(m_Name, name);

        m_Age = age;
    }

    /**
     * 自定义拷贝函数，来做malloc内存的申请，默认的拷贝构造函数只会做浅拷贝，会导致两个对象引用同一块malloc内存！ free的时候就会报错！
     * @param p
     */
    Person(const Person&p)
    {
        m_Name =(char*)malloc(strlen(p.m_Name) + 1);
        strcpy(m_Name, p.m_Name);
        m_Age = p.m_Age;
    }

    ~Person()
    {
        if (m_Name != NULL)
        {
            /**
             * 如果不自定义拷贝函数，这里会重复释放堆区内存
             */
            cout << "Person析构调用" << endl;
            free(m_Name);
            m_Name = NULL;
        }
    }

    char * m_Name; //姓名
    int m_Age;     //年龄
};

void test01()
{
    Person p("德玛西亚", 18);
    cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;

    Person p2(p);
    cout << "姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;
}

int main(){

    test01();
    return EXIT_SUCCESS;
}