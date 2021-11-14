#ifndef BASE_EVENT_HANDLER_H
#define BASE_EVENT_HANDLER_H

#include "../interfaces/event_handler.h"

class BaseEventHandler: public EventHandler
{
public:
	virtual bool handleEvent(Event e) = 0;
	void setNext(std::shared_ptr<EventHandler> _next);
	virtual ~BaseEventHandler() = default;
protected:
	std::shared_ptr<EventHandler> next_handler;
};

#endif