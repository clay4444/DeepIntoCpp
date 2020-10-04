#include <boost/statechart/event.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/transition.hpp>
#include <ctime>
#include <iostream>

namespace sc = boost::statechart;

struct IElapsedTime {
  virtual double ElapsedTime() const = 0;
};

// 定义两个事件
struct EvStartStop : sc::event<EvStartStop> {};
struct EvReset : sc::event<EvReset> {};

struct Active; // 初始状态
struct StopWatch
    : sc::state_machine<StopWatch, Active> { //定义一个状态机，初始状态是Active
  double ElapsedTime() const {
    return state_cast<const IElapsedTime &>().ElapsedTime();
  }
};

struct Stopped; // 停止状态

// simple_state 类模板最多可以接收 4 个参数：第三个参数指定内部初始状态，
//在这里，仅仅 Active有内部状态，该状态就是需要传入到其基类的内部初始状态。
//第四个参数指定是否有某种历史状态需要保持
// Active 是最外层的状态， 因此需要传输其所属状态机
struct Active : IElapsedTime,
                sc::simple_state<Active, StopWatch,Stopped> { //第三个参数是内部初始状态；
public:
  typedef sc::transition<EvReset, Active> reactions;

  Active() : elapsedTime_(0.0) {}
  double ElapsedTime() const { return elapsedTime_; }
  double &ElapsedTime() { return elapsedTime_; }

private:
  double elapsedTime_;
};

// Stopped 和Running 都指定 Active 为其上下文,这将使这两个状态内嵌于 Active中
struct Running : sc::simple_state<Running, Active> {
public:
  typedef sc::transition<EvStartStop, Stopped> reactions;

  Running() : startTime_(std::time(0)) {}
  ~Running() {
    // 类似于子类对象访问父类对象的成员.context<>()可以用于可以直接
    //或间接获得直接或间接的访问状态上下文.此方法也可以直接或间接用
    //于外部状态或这状态机本身.// (例如 context< StopWatch >()).
    context<Active>().ElapsedTime() += std::difftime(std::time(0), startTime_);
  }
  virtual double ElapsedTime() const {
    return context<Active>().ElapsedTime() +
           std::difftime(std::time(0), startTime_);
  }

private:
  std::time_t startTime_;
};

struct Stopped : IElapsedTime, sc::simple_state<Stopped, Active> {
  typedef sc::transition<EvStartStop, Running> reactions;

  virtual double ElapsedTime() const
  {
    return context< Active >().ElapsedTime();
  }
};

int main() {
  StopWatch myWatch;
  myWatch.initiate();

  std::cout << myWatch.ElapsedTime() << "\n";    //0
  sleep(1);

  myWatch.process_event( EvStartStop() );        //进入Running状态，开始计时
  std::cout << myWatch.ElapsedTime() << "\n";    //0
  sleep(1);                                      //睡眠1s
  
  myWatch.process_event( EvStartStop() );        //进入Stopped状态，计时结束
  std::cout << myWatch.ElapsedTime() << "\n";    //1
  sleep(1);                                      //睡眠1s

  myWatch.process_event( EvStartStop() );        //又进入Running状态，开始计时
  std::cout << myWatch.ElapsedTime() << "\n";    //此时还是之前的1呢，
  sleep(1);                                      //睡眠1s

  myWatch.process_event( EvReset() );            //复位了
  std::cout << myWatch.ElapsedTime() << "\n";    //所以是0
 
  return 0;
}