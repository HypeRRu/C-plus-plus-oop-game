#ifndef PLAYER_SAVER_H
#define PLAYER_SAVER_H

#include <string>
#include <memory>

#include "../entities/player.h"
#include "../interfaces/saver.h"

class PlayerSaver
{
public:
	PlayerSaver(
		std::pair<size_t, size_t> _position,
		int _health,
		int _shield,
		int _damage,
		int _money_picked
	);

	PlayerSaver(
		std::istringstream& stream
	);

	~PlayerSaver() = default;

	std::string save() const;
	std::shared_ptr<Player> load() const;
protected:
	std::pair<size_t, size_t> position;
	int health;
	int shield;
	int damage;
	int money_picked;

	std::string offset;
};

#endif