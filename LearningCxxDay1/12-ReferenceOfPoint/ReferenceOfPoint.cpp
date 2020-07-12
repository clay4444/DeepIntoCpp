#include<iostream>
using namespace std;

struct Person
{
    int age;
};

//C语言二级指针的方式
void allocateSpace(Person ** p)
{
    //p指向指针的指针    *p  指针 指向的是person 本体   **p  person本体
    *p = (Person *)malloc(sizeof(Person));
    (*p)->age = 10;
}

void test01()
{
    Person * p = NULL;
    allocateSpace(&p);
    cout << "p.age = " << p->age <<  endl;
}

//指针引用的方式，其实本质上还是二级指针
void allocateSpace2(Person* &pp)   //Person * &pp = p;
{
    pp = (Person *)malloc(sizeof(Person));
    pp->age = 20;
}

void test02()
{
    Person *p = NULL;
    allocateSpace2(p);
    cout << "p.age = " << p->age << endl;
}

int main(){

    //test01();
    test02();
    return EXIT_SUCCESS;
}