#include "../../inc/utils/enemies_generator.h"

EnemiesGenerator::EnemiesGenerator(const Field& _field, double enemy_chance):
	field{_field}, enemy_chance{enemy_chance}
{}

std::map<std::pair<size_t, size_t>, enemy_sptr> EnemiesGenerator::generateEnemies()
{
	std::srand(std::time(NULL));

	std::map<std::pair<size_t, size_t>, enemy_sptr> enemies;
	enemy_sptr _enemy;
	int enemy_offset = (int) (1 / this->enemy_chance);
	int enemy_type;
	bool has_enemy;

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

			has_enemy = (std::rand() % enemy_offset) == 0;
			if (has_enemy)
			{
				enemy_type = std::rand() % 10;
				if (enemy_type >= 0 && enemy_type <= 5)
					/* Regular enemy */
					_enemy = std::make_shared<RegularEnemy>(x, y);
				else if (enemy_type >= 6 && enemy_type <= 8)
					/* Daemon enemy */
					_enemy = std::make_shared<DaemonEnemy>(x, y);
				else if (enemy_type == 9)
					/* Gargoyle enemy */
					_enemy = std::make_shared<GargoyleEnemy>(x, y);
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
