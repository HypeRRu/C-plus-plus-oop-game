#ifndef SAVE_WINDOW_H
#define SAVE_WINDOW_H

#include "base_window.h"
#include "../states/state_save.h"

class StateSave;

class SaveWindow: public BaseWindow
{
public:
	SaveWindow(StateSave& state);
protected:
	StateSave& state;
};

#endif