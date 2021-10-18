#include "../../inc/actions/action_attack.h"

ActionAttack::ActionAttack(BaseEntity& entity1, BaseEntity& entity2):
	entity1{entity1}, entity2{entity2}
{}

BaseEntity& ActionAttack::getEntity1() const
{
	return this->entity1;
}

BaseEntity& ActionAttack::getEntity2() const
{
	return this->entity2;
}

