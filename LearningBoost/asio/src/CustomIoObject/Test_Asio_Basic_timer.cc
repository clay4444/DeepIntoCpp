/*
 * 向 Boost.Asio 中增加新的异步操作，需要实现以下三个类
 * 1.一个派生自 boost::asio::basic_io_object 的类，以表示新的 I/O 对象。使用这个新的 Boost.Asio 扩展的开发者将只会看到这个 I/O 对象。
 * 2.一个派生自 boost::asio::io_service::service 的类，表示一个服务，它被注册为 I/O 服务，可以从 I/O 对象访问它。 服务与 I/O 对象之间的区别是很重要的，
 * 因为在任意给定的时间点，每个 I/O 服务只能有一个服务实例，而一个服务可以被多个 I/O 对象访问
 * 3.一个不派生自任何其它类的类，表示该服务的具体实现。由于在任意给定的时间点每个 I/O 服务只能有一个服务实例，所以服务会为每个 I/O 对象创建一个其具体实现的实例。 该实例管理与相应 I/O 对象有关的内部数据
 */

#include <boost/asio.hpp>
#include <cstddef>

template <typename Service>
class basic_timer 
  : public boost::asio::basic_io_object<Service> 
{ 
  public: 
    explicit basic_timer(boost::asio::io_service &io_service) : boost::asio::basic_io_object<Service>(io_service) 
    {
    }

    void wait(std::size_t seconds) 
    { 
        //
      return this->service.wait(this->implementation, seconds); 
    } 

    template <typename Handler> 
    void async_wait(std::size_t seconds, Handler handler) 
    { 
      this->service.async_wait(this->implementation, seconds, handler); 
    } 
}; 