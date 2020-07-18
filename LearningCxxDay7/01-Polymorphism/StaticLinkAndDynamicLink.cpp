#include<iostream>
using namespace std;

/**
 * 01-静态联编和动态联编
 */

class Animal
{
public:
    //虚函数 virtual关键字！
    virtual void speak()
    {
        cout << "动物在说话" << endl;
    }

    virtual void eat(int a )
    {
        cout << "动物在吃饭" << endl;
    }
};

class Cat :public Animal
{
public:
    void speak()
    {
        cout << "小猫在说话" << endl;
    }

    void eat(int a)
    {
        cout << "小猫在吃饭" << endl;
    }
};

class Dog :public Animal
{
public:
    void speak()
    {
        cout << "小狗在说话" << endl;
    }
};


//动态多态产生条件：
//先有继承关系
//父类中有虚函数，子类重写父类中的虚函数
//父类的指针或引用  指向子类的对象

//对于有父子关系的两个类  指针或者引用 是可以直接转换的
void doSpeak(Animal & animal) //Animal & animal = cat;
{
    //如果地址早就绑定好了，地址早绑定，属于静态联编
    //如果想调用小猫说话，这个时候函数的地址就不能早就绑定好，而是在运行阶段再去绑定函数地址，属于地址晚绑定，叫动态联编
    animal.speak();
}

void test01()
{
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);
}

void test02()
{
    //cout << "sizeof  Animal = " << sizeof (Animal) << endl;

    Animal * animal = new Cat;
    //animal->speak();
    // *(int *)animal 解引用到虚函数表中
    // *(int *)*(int *)animal 解引用到函数speak地址

    //调用猫说话
    ((void(*)()) (*(int *)*(int *)animal)) ();


    //C/C++默认调用惯例  __cdecl
    //用下列调用时候 真实调用惯例  是 __stdcall
    //调用猫吃饭
    typedef void( __stdcall *FUNPOINT)(int);

    (FUNPOINT (*((int*)*(int*)animal + 1)))(10);
}

int main(){
    test01();
    //test02();

    return EXIT_SUCCESS;
}