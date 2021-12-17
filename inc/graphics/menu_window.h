#ifndef MENU_WINDOW_H
#define MENU_WINDOW_H

#include "base_window.h"
#include "../states/state_menu.h"

class StateMenu;

class MenuWindow: public BaseWindow
{
public:
	MenuWindow(StateMenu& state);
protected:
	StateMenu& state;
};

#endif