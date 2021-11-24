#ifndef ENEMIES_TO_KILL_RULE_H
#define ENEMIES_TO_KILL_RULE_H

#include "../interfaces/game_rule.h"
#include "../states/state_gameplay.h"

template<int count>
class EnemiesToKillRule: public GameRule
{
public:
	bool exec(StateGameplay& state) const
	{
		return state.getEnemiesKilled() >= count;
	}
};

#endif