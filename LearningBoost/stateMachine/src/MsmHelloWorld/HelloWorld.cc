#include <iostream>
#include <boost/msm/back/state_machine.hpp>

#include <boost/msm/front/state_machine_def.hpp>
#include <boost/msm/front/functor_row.hpp>

//reference from https://www.jianshu.com/p/6748aa7c117b

namespace {
    namespace msm = boost::msm;
    namespace msmf = boost::msm::front;
    namespace mpl = boost::mpl;
 
    // ----- 定义一个事件
    struct Event1 {};
 
    // ----- 定义一个状态机，需要继承 boost::msm::front:state_machine_def
    struct Sm1_:msmf::state_machine_def<Sm1_>
    {
        // 定义第一个状态：State1， 需要继承自 boost::msm::front:state
        struct State1:msmf::state<> 
        {
            // Entry action
            template <class Event,class Fsm>
            void on_entry(Event const&, Fsm&) const {
                std::cout << "State1::on_entry()" << std::endl;
            }
            // Exit action
            template <class Event,class Fsm>
            void on_exit(Event const&, Fsm&) const {
                std::cout << "State1::on_exit()" << std::endl;
            }
        };

        // 定义第二个状态：End, 它继承的是 boost::msm::front:terminate_state，说明是结束状态；
        struct End:msmf::terminate_state<> {};
 
        // 设置初始状态
        typedef State1 initial_state;
 
        // 状态转移表
        struct transition_table:mpl::vector<
            //          Start   Event   Next    Action      Guard
            msmf::Row < State1, Event1, End,    msmf::none, msmf::none >
        > {};
    };
 
    // Pick a back-end
    typedef msm::back::state_machine<Sm1_> Sm1;
 
    void test()
    {        
        Sm1 sm1;
        sm1.start();  //状态机开始！
        std::cout << "> Send Event1" << std::endl;
        sm1.process_event(Event1());
    }
}
 
int main()
{
    test();
    return 0;
}