#ifndef ENEMIES_COUNT_CONFIURATION_H
#define ENEMIES_COUNT_CONFIURATION_H

#include "../interfaces/configuration.h"
#include "../game_config.h"

template<int cnt>
class EnemiesCountConfiguration: public Configuration
{
public:
	bool exec(GameConfig& config) const
	{
		config.setEnemiesCount(cnt);
		return true;
	}
};

#endif