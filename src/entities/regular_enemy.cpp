#include "../../inc/entities/regular_enemy.h"

RegularEnemy::RegularEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(pos_x, pos_y)
{}

const std::string RegularEnemy::getTextureAlias() const
{
	return "enemy_regular";
}
