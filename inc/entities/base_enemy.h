#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "base_entity.h"
#include "../actions/action_delete_enemy.h"

#include "../actions/action_move.h"
#include <cstdlib>
#include <ctime>
#include <functional>
#include <memory>

class BaseEnemy: public BaseEntity
{
public:
	BaseEnemy(
		size_t pos_x, size_t pos_y,
		size_t health = 100,
		size_t shield = 100,
		size_t damage = 100		
	);
	virtual ~BaseEnemy() = default;
	void changeHealth(int delta);

	void destroy();
	bool canPickItem();

	bool update();

	virtual std::shared_ptr<BaseEnemy> getSharedPtr() = 0;
};

#endif
