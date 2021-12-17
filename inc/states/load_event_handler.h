#ifndef LOAD_EVENT_HANDLER_H
#define LOAD_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_load.h"

class StateLoad;

class LoadEventHandler: public BaseEventHandler
{
public:
	LoadEventHandler(StateLoad& _state);
	bool handleEvent(Event e);
protected:
	StateLoad& state;
};

#endif