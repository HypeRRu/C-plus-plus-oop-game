#include "../../inc/actions/action_delete_enemy.h"

ActionDeleteEnemy::ActionDeleteEnemy(BaseEnemy& _enemy):
	enemy{_enemy}
{}

BaseEnemy& ActionDeleteEnemy::getEnemy() const
{
	return this->enemy;
}
