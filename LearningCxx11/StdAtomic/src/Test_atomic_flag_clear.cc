#include <thread>
#include <vector>
#include <iostream>
#include <atomic>

//结合 std::atomic_flag::test_and_set() 和 std::atomic_flag::clear()，std::atomic_flag 对象可以当作一个简单的自旋锁使用，请看下例：

std::atomic_flag lock = ATOMIC_FLAG_INIT;

void f(int n)
{
    for (int cnt = 0; cnt < 100; ++cnt) {
        while (lock.test_and_set(std::memory_order_acquire))  // acquire lock
             ; // spin
        std::cout << "Output from thread " << n << '\n';
        lock.clear(std::memory_order_release);               // release lock,  这样下一个线程就可以获取到 “锁” 了；
    }
}

int main()
{
    std::vector<std::thread> v;
    for (int n = 0; n < 10; ++n) {
        v.emplace_back(f, n);
    }
    for (auto& t : v) {
        t.join();
    }
}