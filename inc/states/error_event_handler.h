#ifndef ERROR_EVENT_HANDLER_H
#define ERROR_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_error.h"

class StateError;

class ErrorEventHandler: public BaseEventHandler
{
public:
	ErrorEventHandler(StateError& _state);
	bool handleEvent(Event e);
protected:
	StateError& state;
};

#endif