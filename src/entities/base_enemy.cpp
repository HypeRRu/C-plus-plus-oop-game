#include "../../inc/entities/base_enemy.h"

BaseEnemy::BaseEnemy(
	size_t pos_x, size_t pos_y,
	size_t health,
	size_t shield,
	size_t damage
):
	BaseEntity(pos_x, pos_y)
{
	this->health = health;
	this->shield = shield;
	this->damage = damage;
}

void BaseEnemy::decreaseHealth(int delta)
{
	BaseEntity::decreaseHealth(delta);
	if (this->getHealth() <= 0)
		this->destroy();
}

void BaseEnemy::destroy()
{
	ActionDeleteEnemy act(*this);
	this->handleAction(act);
}

bool BaseEnemy::canPickItem()
{
	return false;
}
