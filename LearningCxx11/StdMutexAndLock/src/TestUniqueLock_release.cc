#include <iostream>       // std::cout
#include <vector>         // std::vector
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock

std::mutex mtx;
int count = 0;

void print_count_and_unlock (std::mutex* p_mtx) {
  std::cout << "count: " << count << '\n';
  p_mtx->unlock();  //需要在这里手动释放。
}

void task() {
  std::unique_lock<std::mutex> lck(mtx);
  ++count;
  print_count_and_unlock(lck.release());   //release:  返回指向它所管理的 Mutex 对象的指针，并释放所有权（但是不会释放锁）
}

int main ()
{
  std::vector<std::thread> threads;
  for (int i=0; i<10; ++i)
    threads.emplace_back(task);

  for (auto& x: threads) x.join();

  return 0;
}