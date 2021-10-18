#ifndef ACTION_DELETE_ITEM_H
#define ACTION_DELETE_ITEM_H

#include "action.h"
#include "../items/base_item.h"

class ActionDeleteItem: public Action
{
public:
	ActionDeleteItem(BaseItem& _item);

	BaseItem& getItem() const;
protected:
	/* context */
	BaseItem& item;
};

#endif
