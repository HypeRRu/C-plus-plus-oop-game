#ifndef MAX_STEPS_RULE_H
#define MAX_STEPS_RULE_H

#include "../interfaces/game_rule.h"
#include "../states/state_gameplay.h"

template<int steps_cnt>
class MaxStepsRule: public GameRule
{
public:
	bool exec(StateGameplay& state) const
	{
		return state.getStepsCount() < steps_cnt;
	}
};

#endif