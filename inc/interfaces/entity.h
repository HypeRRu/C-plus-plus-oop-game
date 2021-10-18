#ifndef ENTITY_H
#define ENTITY_H

#include <memory>

class Entity
{
public:
	virtual void spawn() = 0;
	virtual void moveTo(size_t x, size_t y) = 0;
	virtual void changeHealth(int delta) = 0;
	virtual void changeShield(int delta) = 0;
	virtual void changeDamage(int delta) = 0;
	virtual int getHealth() const = 0;
	virtual int getDamage() const = 0;
	virtual int getShield() const = 0;
};

#endif
