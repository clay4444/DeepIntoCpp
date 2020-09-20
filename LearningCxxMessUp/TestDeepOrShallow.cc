#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

class Str{
 public:
  char *value;
  Str(char s[])
  {
    cout<<"调用构造函数..."<<endl;
    int len = strlen(s);
    value = new char[len + 1];
    memset(value,0,len + 1);
    strcpy(value,s);
  }
  Str(Str &v)
  {
    cout<<"调用拷贝构造函数..."<<endl;
    this->value = v.value;  //浅拷贝
    v.value = NULL;    //原来对象的引用指向 NULL， 所以它在析构的时候不会释放
  }
  ~Str()
  {
    cout<<"调用析构函数..."<<endl;
    if(value != NULL)
      delete[] value;
  }
};

int main()
{
  char s[] = "I love BIT";
  Str *a = new Str(s);
  Str *b = new Str(*a);
  delete a;
  cout<<"b对象中的字符串为："<<b->value<<endl;
  delete b;
  return 0;
}