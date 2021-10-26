#include "../../inc/actions/action_player_reach_end.h"

ActionPlayerReachEnd::ActionPlayerReachEnd(BaseEntity& entity, const std::pair<size_t, size_t>& coords):
	entity{entity}, coords{coords}
{}

BaseEntity& ActionPlayerReachEnd::getEntity() const
{
	return this->entity;
}

const std::pair<size_t, size_t>& ActionPlayerReachEnd::getCoords() const
{
	return this->coords;
}
