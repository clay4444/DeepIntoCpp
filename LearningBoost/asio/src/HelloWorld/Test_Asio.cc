#include <boost/asio.hpp> 
#include <iostream> 

void handler(const boost::system::error_code &ec)
{
    std::cout << " 5 s." << std::endl;
}

// int main()
// {
//     boost::asio::io_service io_service;  // I/O 服务抽象了操作系统的接口，允许第一时间进行异步数据处理,  首先定义了一个 I/O 服务 io_service，用于初始化 I/O 对象 timer
//     boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5));  // I/O 对象则用于初始化特定的操作   所有 I/O 对象通常都需要一个 I/O 服务作为它们的构造函数的第一个参数

//     //timer.wait();   //阻塞式的，
//     timer.async_wait(handler);   //该函数调用会立即返回，而不是等待五秒钟

//     //可以理解为io服务是用来管理所有的io对象的。  所以这里其实就是等待所有的异步io完成，然后回调句柄， 可以理解为 run() 是把异步线程中的操作拿到主线程了。
//     io_service.run();   //必须的，因为控制权必须被操作系统接管，才能在五秒之后调用 handler() 函数。 这个操作是阻塞的，

//     return 0;
// }