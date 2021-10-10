#ifndef ACTION_PICK_ITEM_H
#define ACTION_PICK_ITEM_H

#include "action.h"
#include "../items/base_item.h"
#include "../entities/base_entity.h"

class ActionPickItem: public Action
{
public:
	ActionPickItem(BaseEntity& entity, BaseItem& _item);
	ActionType getActionType();
	
	BaseEntity& getEntity();
	BaseItem& getItem();
protected:
	/* context */
	BaseEntity& entity;
	BaseItem& item;
};

#endif
