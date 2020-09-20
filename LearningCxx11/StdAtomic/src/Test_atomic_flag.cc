#include <iostream>              // std::cout
#include <atomic>                // std::atomic, std::atomic_flag, ATOMIC_FLAG_INIT
#include <thread>                // std::thread, std::this_thread::yield
#include <vector>                // std::vector

std::atomic<bool> ready(false);    // can be checked without being set

//如果在初始化时没有明确使用 ATOMIC_FLAG_INIT初始化，那么新创建的 std::atomic_flag 对象的状态是未指定的（unspecified）（既没有被 set 也没有被 clear。）另外，atomic_flag不能被拷贝，也不能 move 赋值。
std::atomic_flag winner = ATOMIC_FLAG_INIT;    //如果某个 std::atomic_flag 对象使用该宏初始化，那么可以保证该 std::atomic_flag 对象在创建时处于 clear 状态。

void count1m(int id)
{
    while (!ready) {
        std::this_thread::yield();
    } // 等待主线程中设置 ready 为 true.

    for (int i = 0; i < 1000000; ++i) {
    } // 计数.

    // 如果某个线程率先执行完上面的计数过程，则输出自己的 ID.
    // 此后其他线程执行 test_and_set 是 if 语句判断为 false，
    // 因此不会输出自身 ID.
    if (!winner.test_and_set()) {  //test_and_set 方法， 注意；返回值是 先前该 std::atomic_flag 对象是否被设置过。
        std::cout << "thread #" << id << " won!\n";
    }
};

int main()
{
    std::vector<std::thread> threads;
    std::cout << "spawning 10 threads that count to 1 million...\n";
    for (int i = 1; i <= 10; ++i)
        threads.push_back(std::thread(count1m, i));
    ready = true;

    for (auto & th:threads)
        th.join();

    return 0;
}