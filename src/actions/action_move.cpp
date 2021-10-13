#include "../../inc/actions/action_move.h"

ActionMove::ActionMove(BaseEntity& entity, const std::pair<size_t, size_t>& coords, bool is_enemy):
	entity{entity}, coords{coords}, is_enemy{is_enemy}
{}

ActionType ActionMove::getActionType()
{
	return ActionType::moveAction;
}

BaseEntity& ActionMove::getEntity() const
{
	return this->entity;
}

const std::pair<size_t, size_t>& ActionMove::getCoords() const
{
	return this->coords;
}

bool ActionMove::getIsEnemy() const
{
	return this->is_enemy;
}
