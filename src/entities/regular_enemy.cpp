#include "../../inc/entities/regular_enemy.h"
#include "../../inc/saves/enemy_saver.h"

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

std::shared_ptr<EnemySaver> RegularEnemy::createSaver() const
{
	return std::make_shared<EnemySaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->health,
		this->shield,
		this->damage,
		this->money_picked,
		"RegularEnemy"
	);
}
