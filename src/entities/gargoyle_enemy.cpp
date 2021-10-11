#include "../../inc/entities/gargoyle_enemy.h"

GargoyleEnemy::GargoyleEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(
		pos_x, pos_y,
		400, 200, 200
	)
{}

const std::string GargoyleEnemy::getTextureAlias() const
{
	return "enemy_gargoyle";
}
