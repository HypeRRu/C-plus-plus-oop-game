#ifndef ENEMIES_GENERATOR_H
#define ENEMIES_GENERATOR_H


#include "../field.h"
#include "../entities/base_entity.h"
#include "../entities/base_enemy.h"
#include "../entities/regular_enemy.h"
#include "../entities/daemon_enemy.h"
#include "../entities/gargoyle_enemy.h"

#include <ctime>
#include <cstdlib>
#include <map>


using enemy_sptr = std::shared_ptr<BaseEnemy>;

class EnemiesGenerator
{
public:
	EnemiesGenerator(const Field& _field, double enemy_chance = 0.05);
	~EnemiesGenerator() = default;

	std::map<std::pair<size_t, size_t>, enemy_sptr> generateEnemies();
protected:
	const Field& field;
	double enemy_chance;
};

#endif
