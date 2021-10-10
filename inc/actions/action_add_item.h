#ifndef ACTION_ADD_ITEM_H
#define ACTION_ADD_ITEM_H

#include "action.h"
#include "../items/base_item.h"

class BaseItem;

class ActionAddItem: public Action
{
public:
	ActionAddItem(BaseItem& item);
	ActionType getActionType();
	BaseItem& getItem() const;
protected:
	/* context */
	BaseItem& item;
};

#endif