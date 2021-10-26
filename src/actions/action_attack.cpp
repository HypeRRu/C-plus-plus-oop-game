#include "../../inc/actions/action_attack.h"

ActionAttack::ActionAttack(BaseEntity& entity1, BaseEntity& entity2):
	entity1{entity1}, entity2{entity2}, damage_caused{0}
{}

BaseEntity& ActionAttack::getEntity1() const
{
	return this->entity1;
}

BaseEntity& ActionAttack::getEntity2() const
{
	return this->entity2;
}

void ActionAttack::setDamageCaused(int _damage)
{
	this->damage_caused = _damage;
}

int ActionAttack::getDamageCaused() const
{
	return this->damage_caused;
}
