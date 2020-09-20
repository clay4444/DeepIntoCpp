#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock, std::unique_lock
                          // std::adopt_lock, std::defer_lock
std::mutex foo,bar;

/*
 * 1.构造函数测试 
 */

void task_a () {
  std::lock (foo,bar);         // simultaneous lock (prevents deadlock)   同时锁定，防止死锁， 所以这里先锁住
  std::unique_lock<std::mutex> lck1 (foo,std::adopt_lock);
  std::unique_lock<std::mutex> lck2 (bar,std::adopt_lock);   //adopt_lock 表示已经初始化 是一个已经被当前线程锁住的 Mutex 对象
  std::cout << "task a\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}

void task_b () {
  // foo.lock(); bar.lock(); // replaced by:
  std::unique_lock<std::mutex> lck1, lck2;
  lck1 = std::unique_lock<std::mutex>(bar,std::defer_lock);  //defer_lock 表示延迟初始化，即：在初始化的时候并不锁住 Mutex 对象
  lck2 = std::unique_lock<std::mutex>(foo,std::defer_lock);
  std::lock (lck1,lck2);       // simultaneous lock (prevents deadlock)   //所以这里后锁住
  std::cout << "task b\n";
  // (unlocked automatically on destruction of lck1 and lck2)
}


/*
 * 2.move assign 函数测试
 * 移动赋值(move assignment)之后，由 x 所管理的 Mutex 对象及其状态将会被新的 std::unique_lock 对象取代。
 * 如果被赋值的对象之前已经获得了它所管理的 Mutex 对象的锁，则在移动赋值(move assignment)之前会调用 unlock 函数释放它所占有的锁。
 */

void print_fifty (char c) {
  std::unique_lock<std::mutex> lck;         // default-constructed
  lck = std::unique_lock<std::mutex>(foo);  // move-assigned   move构造
  for (int i=0; i<50; ++i) { std::cout << c; }
  std::cout << '\n';
}

int main ()
{
  std::thread th1 (task_a);
  std::thread th2 (task_b);

  th1.join();
  th2.join();

  return 0;
}