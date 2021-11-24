#ifndef GAMEPLAY_EVENT_HANDLER_H
#define GAMEPLAY_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_gameplay.h"
#include "movement_handler.h"

class StateGameplay;

class GameplayEventHandler: public BaseEventHandler
{
public:
	GameplayEventHandler(StateGameplay& _state);
	bool handleEvent(Event e);
protected:
	StateGameplay& state;
};

#endif