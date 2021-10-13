#ifndef ACTION_DELETE_ENEMY_H
#define ACTION_DELETE_ENEMY_H

#include "action.h"
#include "../entities/base_enemy.h"

class BaseEnemy;

class ActionDeleteEnemy: public Action
{
public:
	ActionDeleteEnemy(BaseEnemy& _enemy);
	ActionType getActionType();

	BaseEnemy& getEnemy() const;
protected:
	/* context */
	BaseEnemy& enemy;
};

#endif
