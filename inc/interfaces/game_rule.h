#ifndef GAME_RULE_H
#define GAME_RULE_H

#include "../states/state_gameplay.h"

class StateGameplay;

class GameRule
{
public:
	virtual bool exec(StateGameplay& state) const = 0;
};

#endif