#include "../../inc/entities/gargoyle_enemy.h"

GargoyleEnemy::GargoyleEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(
		pos_x, pos_y,
		400, 200, 200
	)
{
	this->setView(std::make_shared<GargoyleEnemyView>(pos_x, pos_y));
}

std::shared_ptr<BaseEnemy> GargoyleEnemy::getSharedPtr()
{
	return std::make_shared<GargoyleEnemy>(*this);
}
