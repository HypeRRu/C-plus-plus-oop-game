#ifndef ACTION_H
#define ACTION_H

#include <memory>

enum class ActionType
{
	defaultAction,
	moveAction,
	effectAction,
	attackAction,
	deleteItemAction,
	deleteEnemyAction,
	pickItemAction,
	addItemAction,
	addEnemyAction
};

class Action
{
public:
	virtual ActionType getActionType() = 0;
	virtual ~Action() = default;
};

#endif
