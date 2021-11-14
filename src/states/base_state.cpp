#include "../../inc/states/base_state.h"

std::shared_ptr<EventHandler> BaseState::getEventHandler() const
{
	return this->handler;
}

void BaseState::setEventHandler(std::shared_ptr<EventHandler> _handler)
{
	this->handler = _handler;
}

