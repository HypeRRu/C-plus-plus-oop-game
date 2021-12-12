#ifndef PLAYER_H
#define PLAYER_H

#include "base_entity.h"
#include "../views/player_view.h"
#include "../actions/action_player_died.h"

class PlayerSaver;

class Player: 
	public BaseEntity
{
public:
	Player(size_t start_x, size_t start_y);
	~Player() = default;

	bool canPickItem() const;
	void changeHealth(int delta);

	void death();

	std::shared_ptr<PlayerSaver> createSaver() const;
};

#endif
