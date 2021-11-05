#include "../../inc/items/shield_item.h"

ShieldItem::ShieldItem(
	size_t x,
	size_t y,
	size_t shield_increase
) : BaseItem(x, y)
{
	this->setView(std::make_shared<ShieldItemView>(x, y));
	this->effect = shield_increase;
}

bool ShieldItem::onPickUp(BaseEntity& entity)
{
	entity.changeShield(this->effect);
	this->destroy();
	return true;
}

const int ShieldItem::getEffect() const
{
	return this->effect;
}

ItemType ShieldItem::getItemType() const
{
	return ItemType::ShieldItem;
}

std::shared_ptr<BaseItem> ShieldItem::getSharedPtr()
{
	return std::make_shared<ShieldItem>(*this);
}
