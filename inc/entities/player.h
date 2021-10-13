#ifndef PLAYER_H
#define PLAYER_H

#include "base_entity.h"

class Player: 
	public BaseEntity
{
public:
	Player(size_t start_x, size_t start_y);
	~Player() = default;

	bool canPickItem();

	const std::string getTextureAlias() const;
};

#endif