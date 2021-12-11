#ifndef MENU_EVENT_HANDLER_H
#define MENU_EVENT_HANDLER_H

#include "base_event_handler.h"
#include "state_menu.h"

class StateMenu;

class MenuEventHandler: public BaseEventHandler
{
public:
	MenuEventHandler(StateMenu& _state);
	bool handleEvent(Event e);
protected:
	StateMenu& state;
};

#endif