#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "../interfaces/entity.h"
#include "../actions/action_add_drawable.h"
#include "../actions/base_observed.h"
#include "../views/base_drawable.h"

class BaseEntity: 
	public Entity,
	public BaseObserved,
	public BaseDrawable
{
public:
	BaseEntity(size_t start_x, size_t start_y);
	virtual ~BaseEntity();

	void moveTo(size_t x, size_t y);
	void spawn();
	virtual bool canPickItem() = 0;
	virtual void changeHealth(int delta);
	void changeShield(int delta);
	void changeDamage(int delta);

	int getHealth() const;
	int getDamage() const;
	int getShield() const;

	const size_t getX() const;
	const size_t getY() const;
protected:
	size_t x;
	size_t y;

	int health;
	int shield;
	int damage;
};

#endif
