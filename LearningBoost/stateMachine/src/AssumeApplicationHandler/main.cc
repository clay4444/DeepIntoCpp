#include "application_event_handler.hpp"

class CustomApplicationEventHandler : public CustomApplicationEventHandlerBase
{
public:
	virtual void empty_to_down_handler() override
	{
		std::cout << "Hello World!" << std::endl;
	}
};

int main()
{
	CustomApplicationEventHandler handler;

	handler.process_event(ApplicationEventHandler::DownEvent{});   //处理 DownEvent 事件；

	return 0;
}
