#include "../../inc/entities/daemon_enemy.h"

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
