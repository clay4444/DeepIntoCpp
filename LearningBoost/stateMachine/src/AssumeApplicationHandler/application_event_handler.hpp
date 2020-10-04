#pragma once

#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/msm/front/euml/common.hpp>
#include <boost/msm/front/functor_row.hpp>
#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>

class CustomApplicationEventHandlerBase;

//这里是实际的状态机定义
class ApplicationEventHandler : public boost::msm::front::state_machine_def<ApplicationEventHandler>
{
public:

    //模拟各种事件
	class MoveEvent {};

	class DownEvent {};

	class UpEvent {};

    //定义各种状态转移 guard
	class DownToUpFunctionType
	{
	public:
		template <class Event, class FrontStateMachine, class SourceState, class TargetState>
		void operator()(Event const& event, FrontStateMachine& front_state_machine, SourceState& s, TargetState& t)
		{
		}
	};

	class MoveToUpFunctionType
	{
	public:
		template <class Event, class FrontStateMachine, class SourceState, class TargetState>
		void operator()(Event const& event, FrontStateMachine& front_state_machine, SourceState& s, TargetState& t)
		{
		}
	};

	class DownToMoveFunctionType
	{
	public:
		template <class Event, class FrontStateMachine, class SourceState, class TargetState>
		void operator()(Event const& event, FrontStateMachine& front_state_machine, SourceState& s, TargetState& t)
		{
		}
	};

	class MoveToMoveFunctionType
	{
	public:
		template <class Event, class FrontStateMachine, class SourceState, class TargetState>
		void operator()(Event const& event, FrontStateMachine& front_state_machine, SourceState& s, TargetState& t)
		{
		}
	};

	class EmptyToDownFunctionType
	{
	public:
		template <class Event, class FrontStateMachine, class SourceState, class TargetState>
		void operator()(Event const& event, FrontStateMachine& front_state_machine, SourceState& s, TargetState& t)
		{
			auto& machine = reinterpret_cast<
				CustomApplicationEventHandlerBase&>(front_state_machine);  //也就是说传递进来的 front_state_machine 应该是 main.cc 中定义的CustomApplicationEventHandler

			machine.empty_to_down_handler(); //报错：读取访问权限冲突，machine 中并无 empty_to_down_handler() 的地址。
		}
	};

    //定义多种状态；
	class Empty : public boost::msm::front::state<>
	{
	public:
		template <class Event, class FrontStateMachine>
		void on_entry(Event const& event, FrontStateMachine& front_state_machine)
		{
		}

		template <class Event, class FrontStateMachine>
		void on_exit(Event const& event, FrontStateMachine& front_state_machine)
		{
		}
	};

	class Move : public boost::msm::front::state<>
	{
	public:
		template <class Event, class FrontStateMachine>
		void on_entry(Event const& event, FrontStateMachine& front_state_machine)
		{
		}

		template <class Event, class FrontStateMachine>
		void on_exit(Event const& event, FrontStateMachine& front_state_machine)
		{
		}
	};

	class Down : public boost::msm::front::state<>
	{
	public:
		template <class Event, class FrontStateMachine>
		void on_entry(Event const& event, FrontStateMachine& front_state_machine)
		{
		}

		template <class Event, class FrontStateMachine>
		void on_exit(Event const& event, FrontStateMachine& front_state_machine)
		{
		}
	};

	class Up : public boost::msm::front::state<>
	{
	public:
		template <class Event, class FrontStateMachine>
		void on_entry(Event const& event, FrontStateMachine& front_state_machine)
		{
		}

		template <class Event, class FrontStateMachine>
		void on_exit(Event const& event, FrontStateMachine& front_state_machine)
		{
		}
	};

	template <class Event, class FrontStateMachine>
	void on_entry(Event const& event, FrontStateMachine& machine) {}

	template <class Event, class FrontStateMachine>
	void on_exit(Event const& event, FrontStateMachine& machine) {}

	using initial_state = Empty;
	using handler = ApplicationEventHandler;

    //定义状态转移表；
	class transition_table : public boost::mpl::vector<
		boost::msm::front::Row<Down, UpEvent, Up, DownToUpFunctionType>,
		boost::msm::front::Row<Down, MoveEvent, Move, DownToMoveFunctionType>,
		boost::msm::front::Row<Move, UpEvent, Up, MoveToUpFunctionType>,
		boost::msm::front::Row<Move, MoveEvent, Move, MoveToMoveFunctionType>,
		boost::msm::front::Row<Empty, DownEvent, Down, EmptyToDownFunctionType>,
		boost::msm::front::Row<Empty, UpEvent, Empty, boost::msm::front::none>,
		boost::msm::front::Row<Empty, MoveEvent, Empty, boost::msm::front::none>,
		boost::msm::front::Row<Up, boost::msm::front::none, Empty, boost::msm::front::none>
	> {};
};    //end


//这里是状态机的封装； 它封装的是上面定义的状态机；
class CustomApplicationEventHandlerBase : public
	boost::msm::back::state_machine<ApplicationEventHandler>
{
public:
	virtual void empty_to_down_handler() = 0;   //定义了一个虚函数
};