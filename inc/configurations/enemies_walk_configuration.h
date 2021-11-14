#ifndef ENEMIES_WALK_CONFIGURATION_H
#define ENEMIES_WALK_CONFIGURATION_H

#include "../interfaces/configuration.h"

template<int steps_cnt>
class EnemiesWalkConfiguration: public Configuration
{
public:
	bool exec(GameConfig& config) const
	{
		config.setEnemiesWalk(steps_cnt);
		return true;
	}
};

#endif