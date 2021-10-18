#include "../../inc/entities/base_entity.h"
#include "../../inc/actions/game_observer.h"

BaseEntity::BaseEntity(size_t start_x, size_t start_y):
	x{start_x}, y{start_y},
	health{100}, shield{100}, damage{100}
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
	ActionAddDrawable act(*this, false);
	this->getObserver().handleAction(act);
}


void BaseEntity::changeHealth(int delta)
{
	this->health += delta;
}

void BaseEntity::changeShield(int delta)
{
	this->shield += delta;
}

void BaseEntity::changeDamage(int delta)
{
	this->damage += delta;
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

const size_t BaseEntity::getX() const
{
	return this->x;
}

const size_t BaseEntity::getY() const
{
	return this->y;
}
