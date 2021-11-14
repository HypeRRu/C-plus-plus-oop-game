#ifndef MONEY_RULE_H
#define MONEY_RULE_H

#include "../interfaces/game_rule.h"
#include "../states/state_gameplay.h"

template<int count>
class MoneyRule: public GameRule
{
public:
	bool exec(StateGameplay& state) const
	{
		return state.getPlayerPtr()->getMoneyPicked() >= count;
	}
};

#endif