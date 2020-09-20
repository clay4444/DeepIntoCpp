// unique_lock::lock/unlock
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock

std::mutex mtx;           // mutex for critical section

void print_thread_id (int id) {
  std::unique_lock<std::mutex> lck (mtx,std::defer_lock);   //延迟上锁
  // critical section (exclusive access to std::cout signaled by locking lck):
  lck.lock();  //调用它所管理的 Mutex 对象的 lock 函数。如果在调用  Mutex 对象的 lock 函数时该 Mutex 对象已被另一线程锁住，则当前线程会被阻塞，直到它获得了锁
  std::cout << "thread #" << id << '\n';
  lck.unlock();  //注意这种方式需要手动释放锁
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