// future example
#include <iostream>             // std::cout
#include <future>               // std::async, std::future
#include <chrono>               // std::chrono::milliseconds


/*
 * 前面已经多次提到过 std::future，那么 std::future 究竟是什么呢？简单地说，std::future 可以用来获取异步任务的结果，因此可以把它当成一种简单的线程间同步的手段。
 * std::future 通常由某个 Provider 创建，你可以把 Provider 想象成一个异步任务的提供者，Provider 在某个线程中设置共享状态的值，
 * 与该共享状态相关联的 std::future 对象调用 get（通常在另外一个线程中） 获取该值，如果共享状态的标志不为 ready，则调用 std::future::get 会阻塞当前的调用者，
 * 直到 Provider 设置了共享状态的值（此时共享状态的标志变为 ready），std::future::get 返回异步任务的值或异常（如果发生了异常）。
 * 
 * 一个有效(valid)的 std::future 对象通常由以下三种 Provider 创建，并和某个共享状态相关联。Provider 可以是函数或者类，其实我们前面都已经提到了，他们分别是：
 * 1.std::async 函数，本文后面会介绍 std::async() 函数。
 * 2.std::promise::get_future，get_future 为 promise 类的成员函数
 */


// a non-optimized way of checking for prime numbers:
bool is_prime(int x)
{
    for (int i = 2; i < x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    // call function asynchronously:   调用异步函数
    std::future < bool > fut = std::async(is_prime, 444444443);

    // do something while waiting for function to set future:
    std::cout << "checking, please wait";
    std::chrono::milliseconds span(100);
    while (fut.wait_for(span) == std::future_status::timeout)    //等待一段时间，  注意这里可以判断状态；
        std::cout << '.';

    bool x = fut.get();         // retrieve return value

    std::cout << "\n444444443 " << (x ? "is" : "is not") << " prime.\n";

    return 0;
}