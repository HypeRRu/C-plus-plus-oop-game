#ifndef PAUSE_EVENT_HANDLER_H
#define PAUSE_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_pause.h"

class StatePause;

class PauseEventHandler: public BaseEventHandler
{
public:
	PauseEventHandler(StatePause& _state);
	bool handleEvent(Event e);
protected:
	StatePause& state;
};

#endif