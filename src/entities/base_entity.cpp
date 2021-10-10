#include "../../inc/entities/base_entity.h"

BaseEntity::BaseEntity(size_t start_x, size_t start_y):
	x{start_x}, y{start_y},
	health{100}, shield{0}, damage{20}
{}

BaseEntity::~BaseEntity()
{}

void BaseEntity::moveTo(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}

void BaseEntity::decreaseHealth(size_t delta)
{
	this->health -= delta;
}

void BaseEntity::increaseHealth(size_t delta)
{
	this->health += delta;
}

void BaseEntity::decreaseShield(size_t delta)
{
	this->shield -= delta;
}

void BaseEntity::increaseShield(size_t delta)
{
	this->shield += delta;
}

void BaseEntity::decreaseDamage(size_t delta)
{
	this->damage -= delta;
}

void BaseEntity::increaseDamage(size_t delta)
{
	this->damage += delta;
}

size_t BaseEntity::getHealth() const
{
	return this->health;
}

size_t BaseEntity::getDamage() const
{
	return this->damage;
}

size_t BaseEntity::getShield() const
{
	return this->shield;
}

