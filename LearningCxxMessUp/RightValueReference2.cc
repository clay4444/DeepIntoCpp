#include <iostream>
using namespace std;

template <typename T>
void processValue(T&& val)
{
}


template <typename T>
void forwardValue(T& val)
{
  processValue(val); //右值参数会变成左值
}

template<typename... Args>
T* Instance(Args&&... args)
{
return new T(std::forward<Args >(args)...);
}


int main() {
// your code goes here
  int&& t = 1;   //t是右值引用
  forwardValue(t);  //但调用forwardValue又变成左值了；

  int i = 1;
  processValue(i);  //i是左值
  processValue(1);
  return 0;
}

