#ifndef ENEMY_BASE_H
#define ENEMY_BASE_H

#include "base_entity.h"
#include "../interfaces/npc.h"

class EnemyBase: public BaseEntity, public NPC
{
public:
	EnemyBase();
	~EnemyBase();

	void spawn();
	void attack();

	void remove();
};

#endif
