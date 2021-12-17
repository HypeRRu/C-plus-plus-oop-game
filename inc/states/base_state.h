#ifndef BASE_STATE_H
#define BASE_STATE_H

#include <memory>
#include "../interfaces/state.h"
#include "../interfaces/event_handler.h"

class BaseState: public State
{
public:
	virtual bool update(int time_passed = 0) = 0;
	virtual void showing() const = 0;
	std::shared_ptr<EventHandler> getEventHandler() const;
	void setEventHandler(std::shared_ptr<EventHandler> _handler);
	virtual ~BaseState() = default;
protected:
	std::shared_ptr<EventHandler> handler;
};

#endif