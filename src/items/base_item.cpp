#include "../../inc/items/base_item.h"

BaseItem::BaseItem(size_t x, size_t y):
	x{x}, y{y}
{}

bool BaseItem::onAdd()
{
	ActionAddItem act(*this);
	return this->handleAction(act);
}

void BaseItem::destroy()
{
	ActionDeleteItem act(*this);
	this->handleAction(act);
}

const size_t BaseItem::getX() const
{
	return this->x;
}

const size_t BaseItem::getY() const
{
	return this->y;
}

