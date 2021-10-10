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

void BaseEnemy::spawn()
{
	ActionAddEnemy act(*this);
	this->handleAction(act);
}

void BaseEnemy::decreaseHealth(size_t delta)
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

void BaseEnemy::attack()
{}

const size_t BaseEnemy::getX() const
{
	return this->x;
}

const size_t BaseEnemy::getY() const
{
	return this->y;
}
