#ifndef DAEMON_ENEMY_H
#define DAEMON_ENEMY_H

#include "base_enemy.h"
#include "../views/daemon_enemy_view.h"

class EnemySaver;

class DaemonEnemy: public BaseEnemy
{
public:
	DaemonEnemy(size_t pos_x, size_t pos_y);
	~DaemonEnemy() = default;

	std::shared_ptr<EnemySaver> createSaver() const;

	std::shared_ptr<BaseEnemy> getSharedPtr();
};

#endif
