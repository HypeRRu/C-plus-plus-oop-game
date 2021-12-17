#ifndef ACTION_PLAYER_DIED_H
#define ACTION_PLAYER_DIED_H

#include "action.h"
#include "../entities/player.h"

class Player;

class ActionPlayerDied: public Action
{
public:
	ActionPlayerDied(Player& _player);

	Player& getPlayer() const;
protected:
	/* context */
	Player& player;
};

#endif
