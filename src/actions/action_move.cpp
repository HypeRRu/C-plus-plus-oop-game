#include "../../inc/actions/action_move.h"

ActionMove::ActionMove(BaseEntity& entity, const std::pair<size_t, size_t>& coords):
	entity{entity}, coords{coords}
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

