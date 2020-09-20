#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

// 避免在临界区中因为抛出异常或return等操作导致没有解锁就退出的问题,  RAII 相关

/*
 * 1. 在std::lock_guard对象构造时，传入的mutex对象(即它所管理的mutex对象)会被当前线程锁住。在lock_guard对象被析构时，
 *    它所管理的mutex对象会自动解锁，不需要程序员手动调用lock和unlock对mutex进行上锁和解锁操作
 * 2. lock_guard对象并不负责管理mutex对象的生命周期，lock_guard对象只是简化了mutex对象的上锁和解锁操作，方便线程对互斥量上锁，
 *    即在某个lock_guard对象的生命周期内，它所管理的锁对象会一直保持上锁状态；而lock_guard的生命周期结束之后，它所管理的锁对象会被解锁
 * 3.  std::lock_guard在构造时只被锁定一次，并且在销毁时解锁
 */

std::mutex mtx;

void print_even (int x) {
    if (x%2==0) std::cout << x << " is even\n";
    else throw (std::logic_error("not even"));  //这里，抛出异常
}

void print_thread_id (int id) {
    try {
        // 栈上的局部变量
        // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
        std::lock_guard<std::mutex> lck (mtx);   //构造时自动获取锁
        print_even(id);
    }
    catch (std::logic_error&) {  //抛出异常之后，lock_guard析构，自动释放锁
        std::cout << "[exception caught]\n";
    }
}

int main ()
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_thread_id,i+1);

    for (auto& th : threads) th.join();

    return 0;
}