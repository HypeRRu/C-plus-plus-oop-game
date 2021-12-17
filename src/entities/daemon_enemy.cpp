#include "../../inc/entities/daemon_enemy.h"
#include "../../inc/saves/enemy_saver.h"

DaemonEnemy::DaemonEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(
		pos_x, pos_y,
		200, 50, 150
	)
{
	this->setView(std::make_shared<DaemonEnemyView>(pos_x, pos_y));
}

std::shared_ptr<BaseEnemy> DaemonEnemy::getSharedPtr()
{
	return std::make_shared<DaemonEnemy>(*this);
}

std::shared_ptr<EnemySaver> DaemonEnemy::createSaver() const
{
	return std::make_shared<EnemySaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->health,
		this->shield,
		this->damage,
		this->money_picked,
		"DaemonEnemy"
	);
}
