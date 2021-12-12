#ifndef ENEMY_SAVER_H
#define ENEMY_SAVER_H

#include <string>
#include <memory>

#include "../entities/base_enemy.h"
#include "../entities/regular_enemy.h"
#include "../entities/daemon_enemy.h"
#include "../entities/gargoyle_enemy.h"
#include "../interfaces/saver.h"

class EnemySaver
{
public:
	EnemySaver(
		std::pair<size_t, size_t> _position,
		int _health,
		int _shield,
		int _damage,
		int _money_picked,
		const std::string& _enemy_type
	);

	EnemySaver(
		std::istringstream& stream
	);

	~EnemySaver() = default;

	std::string save() const;
	std::shared_ptr<BaseEnemy> load() const;
protected:
	std::string enemy_type;
	std::pair<size_t, size_t> position;
	int health;
	int shield;
	int damage;
	int money_picked;

	std::string offset;
};

#endif