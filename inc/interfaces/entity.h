#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

class Entity
{
public:
	virtual void spawn()     = 0;
	virtual void attack()    = 0;
	virtual void moveTo(size_t x, size_t y)   = 0;
	virtual void decreaseHealth(size_t delta) = 0;
	virtual void increaseHealth(size_t delta) = 0;
	virtual void decreaseShield(size_t delta) = 0;
	virtual void increaseShield(size_t delta) = 0;
	virtual void decreaseDamage(size_t delta) = 0;
	virtual void increaseDamage(size_t delta) = 0;
	virtual size_t getHealth() const = 0;
	virtual size_t getDamage() const = 0;
	virtual size_t getShield() const = 0;
};

#endif