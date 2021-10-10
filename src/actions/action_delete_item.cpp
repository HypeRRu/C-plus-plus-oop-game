#include "../../inc/actions/action_delete_item.h"

ActionDeleteItem::ActionDeleteItem(BaseItem& _item):
	item{_item}
{}

ActionType ActionDeleteItem::getActionType()
{
	return ActionType::deleteItemAction;
}

BaseItem& ActionDeleteItem::getItem()
{
	return this->item;
}
