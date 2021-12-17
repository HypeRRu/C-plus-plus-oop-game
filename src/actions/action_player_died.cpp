#include "../../inc/actions/action_player_died.h"

ActionPlayerDied::ActionPlayerDied(Player& _player):
	player{_player}
{}

Player& ActionPlayerDied::getPlayer() const
{
	return this->player;
}
