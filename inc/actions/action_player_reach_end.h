#ifndef ACTION_PLAYER_REACH_END_H
#define ACTION_PLAYER_REACH_END_H

#include "action.h"
#include "../entities/base_entity.h"

class ActionPlayerReachEnd: public Action
{
public:
	ActionPlayerReachEnd(BaseEntity& entity, const std::pair<size_t, size_t>& coords);
	BaseEntity& getEntity() const;
	const std::pair<size_t, size_t>& getCoords() const;
protected:
	BaseEntity& entity;
	const std::pair<size_t, size_t>& coords;
};

#endif
