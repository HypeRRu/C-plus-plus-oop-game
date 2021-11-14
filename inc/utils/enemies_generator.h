#ifndef ENEMIES_GENERATOR_H
#define ENEMIES_GENERATOR_H

#include "../game_config.h"
#include "random_stuff_generator.h"

#include "../field.h"
#include "../entities/base_entity.h"
#include "../entities/base_enemy.h"
#include "../entities/regular_enemy.h"
#include "../entities/daemon_enemy.h"
#include "../entities/gargoyle_enemy.h"

#include <map>
#include <cmath>

using enemy_sptr = std::shared_ptr<BaseEnemy>;

template<typename ...enemies_types>
class EnemiesGenerator
{
public:
	EnemiesGenerator(const Field& _field): field{_field}
	{}
	~EnemiesGenerator() = default;

	std::map<std::pair<size_t, size_t>, enemy_sptr> generateEnemies()
	{
		std::map<std::pair<size_t, size_t>, enemy_sptr> enemies;
		enemy_sptr _enemy;
		int enemy_type;
		bool has_enemy;
		int types_cnt = sizeof...(enemies_types);
		int offset = std::pow(2, types_cnt) - 1;

		int walls_count = 0;
		for (size_t y = 0; y < this->field.getHeight(); y++)
		{
			for (size_t x = 0; x < this->field.getWidth(); x++)
			{
				if (this->field.getCell(x, y).getHasWall())
					++walls_count;
			}
		}
		int possibilities = this->field.getHeight() * this->field.getWidth() - walls_count - 2;
		RandomStuffGenerator generator(
			GameConfig::instance().getEnemiesCount(),
			possibilities
		);

		for (size_t y = 0; y < this->field.getHeight(); y++)
		{
			for (size_t x = 0; x < this->field.getWidth(); x++)
			{
				if (
					(x == this->field.getStart().first && y == this->field.getStart().second) ||
					(x == this->field.getEnd().first && y == this->field.getEnd().second)
				)
					continue;
				if (this->field.getCell(x, y).getHasWall()) 
					continue;

				has_enemy = generator.generateNew();
				if (has_enemy)
				{
					std::srand(std::time(NULL) + y * this->field.getWidth() + x);
					enemy_type = std::rand() % offset;
					std::vector<enemy_sptr> etypes = {std::make_shared<enemies_types>(x, y)...};
					for (int lim = 0, index = 0; lim < offset; lim += (offset + 1 - lim) / 2, ++index)
					{
						if (enemy_type >= lim && enemy_type < lim + (offset + 1 - lim) / 2)
						{
							_enemy = etypes.at(index);
							break;
						}
					}
					enemies.insert(std::pair<std::pair<size_t, size_t>, enemy_sptr>
						{
							std::pair<size_t, size_t>{x, y},
							_enemy
						}
					);
				}
			}
		}

		return enemies;
	}
protected:
	const Field& field;
};

template<>
class EnemiesGenerator<>
{
public:
	EnemiesGenerator(const Field& _field): generator{_field}
	{}
	~EnemiesGenerator() = default;

	std::map<std::pair<size_t, size_t>, enemy_sptr> generateEnemies()
	{
		return generator.generateEnemies();
	}
protected:
	EnemiesGenerator<DaemonEnemy, RegularEnemy, GargoyleEnemy> generator;
};

#endif
