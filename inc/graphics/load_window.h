#ifndef LOAD_WINDOW_H
#define LOAD_WINDOW_H

#include "base_window.h"
#include "../states/state_load.h"

class StateLoad;

class LoadWindow: public BaseWindow
{
public:
	LoadWindow(StateLoad& state);
protected:
	StateLoad& state;
};

#endif