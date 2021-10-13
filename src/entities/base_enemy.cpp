#include "../../inc/entities/base_enemy.h"

BaseEnemy::BaseEnemy(
	size_t pos_x, size_t pos_y,
	size_t health,
	size_t shield,
	size_t damage
):
	BaseEntity(pos_x, pos_y)
{
	this->health = health;
	this->shield = shield;
	this->damage = damage;
}

void BaseEnemy::decreaseHealth(int delta)
{
	BaseEntity::decreaseHealth(delta);
	if (this->getHealth() <= 0)
		this->destroy();
}

void BaseEnemy::destroy()
{
	ActionDeleteEnemy act(*this);
	this->handleAction(act);
}

bool BaseEnemy::canPickItem()
{
	return false;
}

bool BaseEnemy::update()
{
	std::srand(std::time(NULL));
	size_t try_number = 0;
	size_t direction = 0;
	while (try_number < 4)
	{
		direction = std::rand() % 4;
		try_number++;
		switch (direction)
		{
			case 0:
			{
				/* up */
				ActionMove act(
					*this, 
					std::pair<size_t, size_t>{
						this->getX(),
						this->getY() - 1
					}
				);
				if (this->handleAction(act))
					return true;
			}
			case 1:
			{
				/* down */
				ActionMove act(
					*this, 
					std::pair<size_t, size_t>{
						this->getX(),
						this->getY() + 1
					}
				);
				if (this->handleAction(act))
					return true;
			}
			case 2:
			{
				/* right */
				ActionMove act(
					*this, 
					std::pair<size_t, size_t>{
						this->getX() + 1,
						this->getY()
					}
				);
				if (this->handleAction(act))
					return true;
			}
			case 3:
			{
				/* left */
				ActionMove act(
					*this, 
					std::pair<size_t, size_t>{
						this->getX() - 1,
						this->getY()
					}
				);
				if (this->handleAction(act))
					return true;
			}
		}
	}
	return false;
}
