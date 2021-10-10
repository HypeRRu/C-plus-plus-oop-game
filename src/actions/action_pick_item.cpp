#include "../../inc/actions/action_pick_item.h"

ActionPickItem::ActionPickItem(BaseEntity& entity, BaseItem& _item): 
	entity{entity}, item{_item}
{}

ActionType ActionPickItem::getActionType()
{
	return ActionType::pickItemAction;
}
	
BaseItem& ActionPickItem::getItem()
{
	return this->item;
}

BaseEntity& ActionPickItem::getEntity()
{
	return this->entity;
}
