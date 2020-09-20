#include <iostream>       // std::cout
#include <vector>         // std::vector
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::unique_lock, std::try_to_lock

std::mutex mtx;           // mutex for critical section

void print_star () {
  std::unique_lock<std::mutex> lck(mtx,std::try_to_lock);   //try_to_lock_t 是一个标记类，代表立即尝试获取，获取不到不会阻塞
  // print '*' if successfully locked, 'x' otherwise: 
  if (lck.owns_lock())   //返回当前 std::unique_lock 对象是否获得了锁。
    std::cout << '*';
  else                    
    std::cout << 'x';
}

int main ()
{
  std::vector<std::thread> threads;
  for (int i=0; i<500; ++i)
    threads.emplace_back(print_star);

  for (auto& x: threads) x.join();

  return 0;
}