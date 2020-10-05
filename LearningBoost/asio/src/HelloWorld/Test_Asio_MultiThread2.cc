#include <boost/asio.hpp> 
#include <boost/thread.hpp> 
#include <iostream> 

// 另外还有一个不同的方法：不要绑定多个线程到单个 I/O 服务，而是创建多个 I/O 服务。 然后每一个 I/O 服务使用一个线程。 如果 I/O 服务的数量与系统的处理器内核数量相匹配，则异步操作都可以在各自的内核上执行。

void handler1(const boost::system::error_code &ec) 
{ 
  std::cout << "5 s." << std::endl; 
} 

void handler2(const boost::system::error_code &ec) 
{ 
  std::cout << "5 s." << std::endl; 
} 

boost::asio::io_service io_service1; 
boost::asio::io_service io_service2; 

void run1() 
{ 
  io_service1.run(); 
} 

void run2() 
{ 
  io_service2.run(); 
} 

int main() 
{ 
  boost::asio::deadline_timer timer1(io_service1, boost::posix_time::seconds(5)); 
  timer1.async_wait(handler1); 
  boost::asio::deadline_timer timer2(io_service2, boost::posix_time::seconds(5)); 
  timer2.async_wait(handler2); 
  boost::thread thread1(run1); 
  boost::thread thread2(run2); 
  thread1.join(); 
  thread2.join(); 
} 