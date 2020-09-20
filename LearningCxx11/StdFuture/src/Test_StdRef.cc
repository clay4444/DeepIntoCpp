#include <thread>
#include <vector>
#include <iostream>

typedef unsigned long long ULL;


void accumulator_function(const std::vector<int> &v, ULL &acm,
    unsigned int beginIndex, unsigned int endIndex)
{
    acm = 0;
    for (unsigned int i = beginIndex; i < endIndex; ++i)
    {
        acm += v[i];
    }
}

void fun1(std::vector<int> &a, int i)
{
    a[i] = 20;
}

/**
 *  https://www.jianshu.com/p/277675675593
 */
// int main()
// {
//     ULL acm1 = 0;
//     ULL acm2 = 0;
//     std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

//     //暂时没看懂，这里先记住thread的构造中，传递的变量必须使用 stg::ref 把。
//     std::thread t1(accumulator_function, std::ref(v),  //这里为啥使用std::ref(v)， &不行。
//         std::ref(acm1), 0, v.size() / 2);

//     std::thread t2(accumulator_function, std::ref(v),
//         std::ref(acm2), v.size() / 2, v.size());

//     t1.join();
//     t2.join();

//     std::cout << acm1 << "+" << acm2 << "=" << acm1 + acm2 << std::endl;

//     //下面这个为啥使用&可以呢？
//     // std::vector<int> v = { 1,1,1,1,1,1 };
//     // for (auto x : v)
//     //     cout << x << ' ';
//     // cout << endl;
//     // fun(v, 3);  //可以
//     // for (auto x : v)
//     //     cout << x << ' ';

//     return 0;
// }