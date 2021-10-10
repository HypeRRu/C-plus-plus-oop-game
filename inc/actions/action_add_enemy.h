#ifndef ACTION_ADD_ENEMY_H
#define ACTION_ADD_ENEMY_H

#include "action.h"
#include "../entities/base_enemy.h"

class BaseEnemy;

class ActionAddEnemy: public Action
{
public:
	ActionAddEnemy(BaseEnemy& enemy);
	ActionType getActionType();
	BaseEnemy& getEnemy() const;
protected:
	/* context */
	BaseEnemy& enemy;
};

#endif