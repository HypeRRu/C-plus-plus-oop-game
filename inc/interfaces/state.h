#ifndef STATE_H
#define STATE_H

#include <memory>
#include "event_handler.h"

class State
{
public:
	virtual bool update(int time_passed = 0) = 0;
	virtual std::shared_ptr<EventHandler> getEventHandler() const = 0;
	virtual void setEventHandler(std::shared_ptr<EventHandler> _handler) = 0;
	virtual void showing() const = 0;
	virtual ~State() = default;
};

#endif