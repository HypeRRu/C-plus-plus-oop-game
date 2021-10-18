#include "../../inc/entities/regular_enemy.h"

RegularEnemy::RegularEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(
		pos_x, pos_y
	)	
{
	this->setView(std::make_shared<RegularEnemyView>(pos_x, pos_y));
}

std::shared_ptr<BaseEnemy> RegularEnemy::getSharedPtr()
{
	return std::make_shared<RegularEnemy>(*this);
}
