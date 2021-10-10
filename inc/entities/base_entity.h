#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "../interfaces/entity.h"
#include "../actions/base_observed.h"

class BaseEntity: public Entity
{
public:
	BaseEntity(size_t start_x, size_t start_y);
	virtual ~BaseEntity();

	void moveTo(size_t x, size_t y);
	virtual void spawn() = 0;
	virtual void attack() = 0;

	virtual void decreaseHealth(size_t delta);
	void increaseHealth(size_t delta);
	void decreaseShield(size_t delta);
	void increaseShield(size_t delta);
	void decreaseDamage(size_t delta);
	void increaseDamage(size_t delta);

	size_t getHealth() const;
	size_t getDamage() const;
	size_t getShield() const;
protected:
	size_t x;
	size_t y;

	size_t health;
	size_t shield;
	size_t damage;
};

#endif
