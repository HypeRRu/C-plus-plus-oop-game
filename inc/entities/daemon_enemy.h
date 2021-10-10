#ifndef DAEMON_ENEMY_H
#define DAEMON_ENEMY_H

#include "base_enemy.h"

class DaemonEnemy: public BaseEnemy
{
public:
	DaemonEnemy(size_t pos_x, size_t pos_y);
	~DaemonEnemy() = default;

	const std::string getTextureAlias() const;
};

#endif
