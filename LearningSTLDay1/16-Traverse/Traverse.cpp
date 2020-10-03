#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << endl;
        m_Count++;
    }

    int m_Count = 0;
};

//for_each  用于遍历
//有返回值的
void test01()
{
    vector<int>v;
    for (int i = 0; i < 10;i++)
    {
        v.push_back(i);
    }

    MyPrint print = for_each(v.begin(), v.end(), MyPrint());

    cout << "print.count = " << print.m_Count << endl;

}

//for_each可以绑定参数输出
class MyPrint2 :public binary_function<int,int,void>
{
public:
    void operator()(int val , int start) const
    {
        cout << val << endl;

    }

};

void test02()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    for_each(v.begin(), v.end(),  bind2nd( MyPrint2(), 1000));

}


//transform算法 将指定容器区间元素搬运到另一容器中
class MyTransform
{
public:
    int operator()(int val)
    {
        return val + 10000;
    }
};
void test03()
{
    vector<int>v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    vector<int>v2;
    v2.resize(v.size()); // 必须要初始容量！

    transform(v.begin(), v.end(), v2.begin(), MyTransform());

    for_each(v2.begin(), v2.end(), [](int val){cout << val << " "; });

}

int main(){
    //test01();
    //test02();
    test03();

    return EXIT_SUCCESS;
}