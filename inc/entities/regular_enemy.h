#ifndef REGULAR_ENEMY_H
#define REGULAR_ENEMY_H

#include "base_enemy.h"
#include "../views/regular_enemy_view.h"

class EnemySaver;

class RegularEnemy: public BaseEnemy
{
public:
	RegularEnemy(size_t pos_x, size_t pos_y);
	~RegularEnemy() = default;

	std::shared_ptr<EnemySaver> createSaver() const;

	std::shared_ptr<BaseEnemy> getSharedPtr();
};

#endif
