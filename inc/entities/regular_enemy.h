#ifndef REGULAR_ENEMY_H
#define REGULAR_ENEMY_H

#include "base_enemy.h"

class RegularEnemy: public BaseEnemy
{
public:
	RegularEnemy(size_t pos_x, size_t pos_y);
	~RegularEnemy() = default;

	const std::string getTextureAlias() const;
};

#endif
