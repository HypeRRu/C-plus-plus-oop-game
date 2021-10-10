#include "../../inc/entities/player.h"

Player::Player(size_t start_x, size_t start_y):
	BaseEntity(start_x, start_y)
{}

void Player::spawn()
{}

void Player::attack()
{}

void Player::pickItem()
{}

void Player::onReachEnd()
{}

const size_t Player::getX() const
{
	return this->x;
}

const size_t Player::getY() const
{
	return this->y;
}

const std::string Player::getTextureAlias() const
{
	return "player";
}