#ifndef ACTION_ATTACK_H
#define ACTION_ATTACK_H

#include "action.h"

// #include "../entities/player.h"
#include "../entities/base_entity.h"

class ActionAttack: public Action
{
public:
	ActionAttack(BaseEntity& entity1, BaseEntity& entity2);
	ActionType getActionType();
	
	BaseEntity& getEntity1() const;
	BaseEntity& getEntity2() const;
protected:
	/* context */
	BaseEntity& entity1;
	BaseEntity& entity2;
};

#endif
