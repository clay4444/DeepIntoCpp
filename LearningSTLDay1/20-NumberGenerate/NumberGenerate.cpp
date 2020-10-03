#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> //accumulate算法头文件


//accumulate算法 计算容器元素累计总和
void test01()
{
    vector<int>v;
    for (int i = 0; i <= 100;i++)
    {
        v.push_back(i);
    }

    int num = accumulate(v.begin(), v.end(),1000); // 参数3代表 累加起始值

    cout << "num = " << num << endl;
}

//fill算法 向容器中添加元素
void test02()
{
    vector<int>v;
    v.resize(10);

    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(), [](int val){cout << val << " "; });
    cout << endl;

}


int main(){

    //test01();
    test02();

    return EXIT_SUCCESS;
}