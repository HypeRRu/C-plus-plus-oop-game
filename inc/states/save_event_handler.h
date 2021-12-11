#ifndef SAVE_EVENT_HANDLER_H
#define SAVE_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_save.h"

class StateSave;

class SaveEventHandler: public BaseEventHandler
{
public:
	SaveEventHandler(StateSave& _state);
	bool handleEvent(Event e);
protected:
	StateSave& state;
};

#endif