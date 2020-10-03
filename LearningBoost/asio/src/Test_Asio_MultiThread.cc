 #include <boost/asio.hpp> 
 #include <boost/thread.hpp> 
 #include <iostream> 
 
 void handler1(const boost::system::error_code &ec) 
 { 
   std::cout << "5 s." << std::endl; 
 } 
 
 void handler2(const boost::system::error_code &ec) 
 { 
   std::cout << "5 s." << std::endl; 
 } 
 
 boost::asio::io_service io_service_; 
 
 void run() 
 { 
   io_service_.run(); //两个线程同时调用 run() 方法，所以：如果第二个计时器触发时第一个仍在执行，则第二个句柄就会在第二个线程中执行；
                     //如果第二个计时器触发时第一个已经结束了，则 I/O 服务可以自由选择任一线程

                     //当然，也可以每个thread持有独立的 io_service。
} 
 
//  int main() 
//  {
//    boost::asio::deadline_timer timer1(io_service_, boost::posix_time::seconds(5)); 
//    timer1.async_wait(handler1); 
//    boost::asio::deadline_timer timer2(io_service_, boost::posix_time::seconds(5)); 
//    timer2.async_wait(handler2);

//    //通过boost创建的thread
//    boost::thread thread1(run);
//    boost::thread thread2(run); 
//    thread1.join(); 
//    thread2.join(); 
//  } 