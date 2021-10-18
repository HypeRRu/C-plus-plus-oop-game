#include "../../inc/items/base_item.h"
#include "../../inc/actions/game_observer.h"

BaseItem::BaseItem(size_t x, size_t y):
	x{x}, y{y}
{}

bool BaseItem::onAdd()
{
	ActionAddDrawable act(*this, false);
	return this->getObserver().handleAction(act);
}

void BaseItem::destroy()
{
	ActionDeleteItem act(*this);
	this->getObserver().handleAction(act);
}

const size_t BaseItem::getX() const
{
	return this->x;
}

const size_t BaseItem::getY() const
{
	return this->y;
}

BaseItem::BaseItem(const BaseItem& other): BaseDrawable(other),
	x{x}, y{y}
{}

BaseItem::BaseItem(BaseItem&& other): BaseDrawable(other),
	x{x}, y{y}
{}

BaseItem& BaseItem::operator =(const BaseItem& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	this->x = other.x;
	this->y = other.y;

	return *this;
}

BaseItem& BaseItem::operator =(BaseItem&& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	std::swap(this->x, other.x);
	std::swap(this->y, other.y);
	
	return *this;
}

