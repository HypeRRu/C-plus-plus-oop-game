#include "../../inc/entities/base_entity.h"
#include "../../inc/actions/game_observer.h"

BaseEntity::BaseEntity(size_t start_x, size_t start_y):
	x{start_x}, y{start_y},
	health{100}, shield{100}, 
	damage{100}, money_picked{0}
{}

BaseEntity::~BaseEntity()
{}

void BaseEntity::moveTo(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}

void BaseEntity::spawn()
{
	size_t draw_layer = 2;
	ActionAddDrawable act(*this, draw_layer);
	this->getObserver().handleAction(act);
}


void BaseEntity::changeHealth(int delta)
{
	this->health += delta;
	if (this->health < 0)
		this->health = 0;
}

void BaseEntity::changeShield(int delta)
{
	this->shield += delta;
}

void BaseEntity::changeDamage(int delta)
{
	this->damage += delta;
}

void BaseEntity::changeMoneyPicked(int delta)
{
	this->money_picked += delta;
}

int BaseEntity::getHealth() const
{
	return this->health;
}

int BaseEntity::getDamage() const
{
	return this->damage;
}

int BaseEntity::getShield() const
{
	return this->shield;
}

int BaseEntity::getMoneyPicked() const
{
	return this->money_picked;
}

const size_t BaseEntity::getX() const
{
	return this->x;
}

const size_t BaseEntity::getY() const
{
	return this->y;
}
