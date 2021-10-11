#include "../../inc/entities/player.h"

Player::Player(size_t start_x, size_t start_y):
	BaseEntity(start_x, start_y)
{}

bool Player::canPickItem()
{
	return true;
}

const std::string Player::getTextureAlias() const
{
	return "player";
}
