#include <iostream>       // std::cout
#include <functional>     // std::ref
#include <thread>         // std::thread
#include <future>         // std::promise, std::future

/*
 * 和scale里 promice 的目的一样,  promise也是一种provider
 */

void print_int1(std::future<int>& fut) {
    int x = fut.get(); // 获取共享状态的值.
    std::cout << "value: " << x << '\n'; // 打印 value: 10.
}

// int main ()
// {
//     std::promise<int> prom; // 生成一个 std::promise<int> 对象.

//     std::future<int> fut = prom.get_future(); // 和 future 关联.
    
//     std::thread t(print_int, std::ref(fut)); // 将 future 交给另外一个线程t.
    
//     prom.set_value(10); // 主线程中设置共享状态的值, 此处和线程t会自动保持同步（不需要额外的线程同步手段）.
//     t.join();
    
//     return 0;
// }