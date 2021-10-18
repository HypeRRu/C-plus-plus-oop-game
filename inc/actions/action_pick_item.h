#ifndef ACTION_PICK_ITEM_H
#define ACTION_PICK_ITEM_H

#include "action.h"
#include "../items/base_item.h"
#include "../entities/base_entity.h"

class ActionPickItem: public Action
{
public:
	ActionPickItem(BaseEntity& entity, BaseItem& _item);
	
	BaseEntity& getEntity() const;
	BaseItem& getItem() const;
protected:
	/* context */
	BaseEntity& entity;
	BaseItem& item;
};

#endif
