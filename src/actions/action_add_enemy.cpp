#include "../../inc/actions/action_add_enemy.h"

ActionAddEnemy::ActionAddEnemy(BaseEnemy& enemy):
	enemy{enemy}
{}

ActionType ActionAddEnemy::getActionType()
{
	return ActionType::addEnemyAction;
}

BaseEnemy& ActionAddEnemy::getEnemy() const
{
	return this->enemy;
}
