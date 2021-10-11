#ifndef BASE_ENTITY_H
#define BASE_ENTITY_H

#include "../interfaces/entity.h"
#include "../actions/action_add_drawable.h"
#include "../interfaces/drawable.h"
#include "../actions/base_observed.h"

class BaseEntity: 
	public Entity,
	public BaseObserved,
	virtual public Drawable
{
public:
	BaseEntity(size_t start_x, size_t start_y);
	virtual ~BaseEntity();

	void moveTo(size_t x, size_t y);
	void spawn();
	virtual bool canPickItem() = 0;

	virtual void decreaseHealth(int delta);
	void increaseHealth(int delta);
	void decreaseShield(int delta);
	void increaseShield(int delta);
	void decreaseDamage(int delta);
	void increaseDamage(int delta);

	int getHealth() const;
	int getDamage() const;
	int getShield() const;

	const size_t getX() const;
	const size_t getY() const;

	virtual const std::string getTextureAlias() const = 0;
protected:
	size_t x;
	size_t y;

	int health;
	int shield;
	int damage;
};

#endif
