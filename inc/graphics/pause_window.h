#ifndef PAUSE_WINDOW_H
#define PAUSE_WINDOW_H

#include "base_window.h"
#include "../states/state_pause.h"

class StatePause;

class PauseWindow: public BaseWindow
{
public:
	PauseWindow(StatePause& state);
protected:
	StatePause& state;
};

#endif