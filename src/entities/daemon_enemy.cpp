#include "../../inc/entities/daemon_enemy.h"

DaemonEnemy::DaemonEnemy(size_t pos_x, size_t pos_y):
	BaseEnemy(
		pos_x, pos_y,
		200, 150, 150
	)
{}

const std::string DaemonEnemy::getTextureAlias() const
{
	return "enemy_daemon";
}
