#include "../../inc/states/error_event_handler.h"

ErrorEventHandler::ErrorEventHandler(StateError& _state):
	state{_state}
{
	this->setNext(nullptr);
}

bool ErrorEventHandler::handleEvent(Event e)
{
	switch (e)
	{
		case Event::EventGoBack:
			this->state.back();
			return true;
		case Event::EventGameClosed:
			this->state.getGame().exit();
			return true;
		default:
			if (this->next_handler.get())
				return this->next_handler->handleEvent(e);
	}
	return false;
}
