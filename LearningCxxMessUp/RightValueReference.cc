#include <iostream>
using namespace std;

int g_constructCount=0;
int g_copyConstructCount=0;
int g_destructCount=0;

/*
 * 右值引用  A&& a = GetA();
 * 1.GetA()返回的变量的生命周期和a变量保持一致， 而且此时只有一次拷贝构造，一次析构
 * 2.T&&表示的值类型不确定，可能是左值又可能是右值。
 * 3.T&& t在发生自动类型推断的时候，它是未定的引用类型（universal references），如果被一个左值初始化，它就是一个左值；如果它被一个右值初始化，它就是一个右值，它是左值还是右值取决于它的初始化。
 * 我们再回过头看上面的代码，对于函数template<typename T>void f(T&& t)，当参数为右值10的时候，根据universal references的特点，
 * t被一个右值初始化，那么t就是右值；当参数为左值x时，t被一个左值引用初始化，那么t就是一个左值。需要注意的是，仅仅是当发生自动类型推导（如函数模板的类型自动推导，或auto关键字）的时候，T&&才是universal references
 *
 */

struct A
{
  A(){
    cout<<"construct: "<<++g_constructCount<<endl;
  }

  A(const A& a)
  {
    cout<<"copy construct: "<<++g_copyConstructCount <<endl;
  }
  ~A()
  {
    cout<<"destruct: "<<++g_destructCount<<endl;
  }
};

A GetA()
{
  return A();  //拷贝构造第一次调用： GetA()函数内部创建的对象返回出来构造一个临时对象产生的
}

template<typename T>
void f(T&& t){}

int main() {
  //右值引用，GetA() 返回的对象在函数结束后生命周期会延续，和变量 a 的生命周期保持一致。
  //会调用一次拷贝构造，一次析构，原因在于右值引用绑定了右值，让临时右值的生命周期延长了。我们可以利用这个特点做一些性能优化，即避免临时对象的拷贝构造和析构。
  A&& a = GetA();

  //左值引用，会调用两次拷贝构造，两次析构
  A b = GetA();  //拷贝构造函数的第二次调用：在main函数中构造a对象产生的


  f(10); //t是右值

  int x = 10;
  f(x); //t是左值


  return 0;
}