#include "../../inc/entities/player.h"
#include "../../inc/actions/game_observer.h"

Player::Player(size_t start_x, size_t start_y):
	BaseEntity(
		start_x, start_y
	)
{
	this->setView(std::make_shared<PlayerView>(start_x, start_y));
}

bool Player::canPickItem() const
{
	return true;
}

void Player::changeHealth(int delta)
{
	BaseEntity::changeHealth(delta);
	if (this->getHealth() <= 0)
		this->death();
}

void Player::death()
{
	ActionPlayerDied act(*this);
	this->getObserver().handleAction(act);
}
