#include "../../inc/actions/action_delete_enemy.h"

ActionDeleteEnemy::ActionDeleteEnemy(BaseEnemy& _enemy):
	enemy{_enemy}
{}

ActionType ActionDeleteEnemy::getActionType()
{
	return ActionType::deleteEnemyAction;
}

BaseEnemy& ActionDeleteEnemy::getEnemy()
{
	return this->enemy;
}
