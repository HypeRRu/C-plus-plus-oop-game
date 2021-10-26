#include "../../inc/entities/base_enemy.h"
#include "../../inc/actions/game_observer.h"

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

void BaseEnemy::changeHealth(int delta)
{
	BaseEntity::changeHealth(delta);
	if (this->getHealth() <= 0)
		this->destroy();
}

void BaseEnemy::destroy()
{
	ActionDeleteEnemy act(*this);
	this->getObserver().handleAction(act);
}

bool BaseEnemy::canPickItem() const
{
	return false;
}

#include <iostream>
bool BaseEnemy::update()
{
	std::hash<BaseEnemy*> hash;
	std::srand(std::time(NULL) + hash(this));
	int try_number = 0;
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
				if (this->getObserver().handleAction(act))
					return true;
				break;
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
				if (this->getObserver().handleAction(act))
					return true;
				break;
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
				if (this->getObserver().handleAction(act))
					return true;
				break;
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
				if (this->getObserver().handleAction(act))
					return true;
				break;
			}
			default:
				break;
		}
	}
	return false;
}
