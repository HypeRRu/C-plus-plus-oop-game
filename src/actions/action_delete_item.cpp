#include "../../inc/actions/action_delete_item.h"

ActionDeleteItem::ActionDeleteItem(BaseItem& _item):
	item{_item}
{}

BaseItem& ActionDeleteItem::getItem() const
{
	return this->item;
}
