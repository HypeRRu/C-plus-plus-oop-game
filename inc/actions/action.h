#ifndef ACTION_H
#define ACTION_H

#include <memory>

enum class ActionType
{
	defaultAction,
	moveAction,
	attackAction,
	deleteItemAction,
	deleteEnemyAction,
	pickItemAction,
	addDrawableAction,
	playerReachEndAction
};

class Action
{
public:
	virtual ActionType getActionType() = 0;
};

#endif
