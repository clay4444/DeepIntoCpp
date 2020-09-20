#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;

//拷贝构造 和 移动构造

// 打印一次
int test1()
{
  string st = "I love code";
  vector<string> vc ;
  vc.push_back(move(st));  //调用move函数之后，st字符串为空
  cout<<vc[0]<<endl;
  if(!st.empty())
    cout<<st<<endl;

  return 0;
}

// 打印两次
int test2()
{
  string st = "I love code";
  vector<string> vc ;
  vc.push_back(st);    //原来的字符串不变
  cout<<vc[0]<<endl;
  if(!st.empty())
    cout<<st<<endl;

  return 0;
}

int main()
{
  //test1();
  test2();
}