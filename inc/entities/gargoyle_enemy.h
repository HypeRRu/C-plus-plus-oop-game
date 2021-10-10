#ifndef GARGOYLE_ENEMY_H
#define GARGOYLE_ENEMY_H

#include "base_enemy.h"

class GargoyleEnemy: public BaseEnemy
{
public:
	GargoyleEnemy(size_t pos_x, size_t pos_y);
	~GargoyleEnemy() = default;

	const std::string getTextureAlias() const;
};

#endif
