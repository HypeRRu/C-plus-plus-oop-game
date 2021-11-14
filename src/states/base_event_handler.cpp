#include "../../inc/states/base_event_handler.h"

void BaseEventHandler::setNext(std::shared_ptr<EventHandler> _next)
{
	this->next_handler = _next;
}
