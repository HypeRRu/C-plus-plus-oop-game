#include "../../inc/actions/action_add_item.h"

ActionAddItem::ActionAddItem(BaseItem& item):
	item{item}
{}

ActionType ActionAddItem::getActionType()
{
	return ActionType::addItemAction;
}

BaseItem& ActionAddItem::getItem() const
{
	return this->item;
}
