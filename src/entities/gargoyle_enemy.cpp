#include "../../inc/entities/gargoyle_enemy.h"
#include "../../inc/saves/enemy_saver.h"

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

std::shared_ptr<EnemySaver> GargoyleEnemy::createSaver() const
{
	return std::make_shared<EnemySaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->health,
		this->shield,
		this->damage,
		this->money_picked,
		"GargoyleEnemy"
	);
}
