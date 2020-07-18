#include<iostream>
using namespace std;

/**
 * 03-虚析构 和 纯虚析构
 */

class Animal
{
public:
    Animal()
    {
        cout << "Animal的构造函数调用" << endl;
    }
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }
    //如果子类中有指向堆区的属性，那么要利用虚析构技术 在delete的时候 调用子类的析构函数！
    //virtual ~Animal()
    //{
    //	cout << "Animal的析构函数调用" << endl;
    //}

    //纯虚析构 需要有声明 也需要有实现（因为父类也可能会有堆区数据啊！）： 类内声明，类外实现！
    //如果一个类中 有了 纯虚析构函数，那么这个类也属于抽象类，无法实例化对象了！
    virtual ~Animal() = 0;
};


Animal::~Animal()
{
    cout << "Animal的纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
    Cat(char * name)
    {
        cout << "Cat的构造函数调用" << endl;
        this->m_Name = new char[strlen(name) + 1];
        strcpy(this->m_Name, name);
    }

    virtual void speak()
    {
        cout << this->m_Name <<" 小猫在说话" << endl;
    }

    ~Cat()
    {
        if (this->m_Name)
        {
            cout << "Cat的析构函数调用" << endl;
            delete[] this->m_Name;
            this->m_Name = NULL;
        }
    }
    char * m_Name;
};

void test01()
{
    Animal * animal = new Cat("Tom");
    animal->speak();

    delete animal;  //注意：如果父类的析构函数不是虚析构函数，那么不会调用子类的析构函数！
}

int main() {
    test01();
    //Animal aaa;  在Animal中有了纯虚析构，也属于抽象类

    return EXIT_SUCCESS;
}