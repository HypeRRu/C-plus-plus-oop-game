#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <memory>
#include "../game_config.h"

class EventHandler
{
public:
	virtual bool handleEvent(Event e) = 0;
	virtual void setNext(std::shared_ptr<EventHandler> _next) = 0;
};

#endif