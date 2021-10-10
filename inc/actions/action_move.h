#ifndef ACTION_MOVE_H
#define ACTION_MOVE_H

#include "action.h"

#include "../entities/base_entity.h"

class ActionMove: public Action
{
public:
	ActionMove(BaseEntity& entity, const std::pair<size_t, size_t>& coords);
	ActionType getActionType();
	BaseEntity& getEntity() const;
	const std::pair<size_t, size_t>& getCoords() const;
protected:
	/* context */
	BaseEntity& entity;
	const std::pair<size_t, size_t>& coords;
};

#endif
