#include "../../inc/items/base_item.h"
#include "../../inc/actions/game_observer.h"

BaseItem::BaseItem(size_t x, size_t y, int effect):
	x{x}, y{y}, effect{effect}
{}

bool BaseItem::onAdd()
{
	size_t draw_layer = 1;
	ActionAddDrawable act(*this, draw_layer);
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
	x{other.x}, y{other.y}, effect{effect}
{}

BaseItem::BaseItem(BaseItem&& other): BaseDrawable(other),
	x{other.x}, y{other.y}
{}

BaseItem& BaseItem::operator =(const BaseItem& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	this->x = other.x;
	this->y = other.y;
	this->effect = other.effect;

	return *this;
}

BaseItem& BaseItem::operator =(BaseItem&& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	std::swap(this->x, other.x);
	std::swap(this->y, other.y);
	std::swap(this->effect, other.effect);
	
	return *this;
}

