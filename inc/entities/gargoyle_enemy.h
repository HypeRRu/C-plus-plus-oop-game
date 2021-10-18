#ifndef GARGOYLE_ENEMY_H
#define GARGOYLE_ENEMY_H

#include "base_enemy.h"
#include "../views/gargoyle_enemy_view.h"

class GargoyleEnemy: public BaseEnemy
{
public:
	GargoyleEnemy(size_t pos_x, size_t pos_y);
	~GargoyleEnemy() = default;

	std::shared_ptr<BaseEnemy> getSharedPtr();
};

#endif
