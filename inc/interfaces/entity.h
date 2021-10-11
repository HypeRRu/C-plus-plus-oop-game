#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

class Entity
{
public:
	virtual void spawn() = 0;
	virtual void moveTo(size_t x, size_t y) = 0;
	virtual void decreaseHealth(int delta)  = 0;
	virtual void increaseHealth(int delta)  = 0;
	virtual void decreaseShield(int delta)  = 0;
	virtual void increaseShield(int delta)  = 0;
	virtual void decreaseDamage(int delta)  = 0;
	virtual void increaseDamage(int delta)  = 0;
	virtual int getHealth() const = 0;
	virtual int getDamage() const = 0;
	virtual int getShield() const = 0;
};

#endif
