#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_entity.h"
#include "../interfaces/drawable.h"
#include "../actions/base_observed.h"
#include "../actions/action_add_enemy.h"
#include "../actions/action_delete_enemy.h"

class BaseEnemy: 
	public BaseEntity,
	public BaseObserved,
	virtual public Drawable
{
public:
	BaseEnemy(
		size_t pos_x, size_t pos_y,
		size_t health = 100,
		size_t shield = 100,
		size_t damage = 100
	);
	virtual ~BaseEnemy() = default;
	void decreaseHealth(size_t delta);

	void spawn();
	void attack();
	void destroy();

	/*void pickItem();
	void onReachEnd();*/

	const size_t getX() const;
	const size_t getY() const;

	const std::string getTextureAlias() const = 0;
};

#endif
