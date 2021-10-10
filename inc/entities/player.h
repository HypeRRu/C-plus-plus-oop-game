#ifndef PLAYER_H
#define PLAYER_H

#include "base_entity.h"
#include "../interfaces/playable.h"
#include "../interfaces/drawable.h"
#include "../actions/base_observed.h"

class Player: 
	public BaseEntity, 
	public Playable, 
	public BaseObserved,
	virtual public Drawable
{
public:
	Player(size_t start_x, size_t start_y);
	~Player() = default;

	void spawn();
	void attack();

	void pickItem();
	void onReachEnd();

	const size_t getX() const;
	const size_t getY() const;

	const std::string getTextureAlias() const;
};

#endif