#include "../../inc/items/heal_item.h"

HealItem::HealItem(
	size_t x,
	size_t y,
	size_t healing_amount
) : BaseItem(x, y)
{
	this->setView(std::make_shared<HealItemView>(x, y));
	this->effect = healing_amount;
}

bool HealItem::onPickUp(BaseEntity& entity)
{
	entity.changeHealth(this->effect);
	this->destroy();
	return true;
}

const int HealItem::getEffect() const
{
	return this->effect;
}

ItemType HealItem::getItemType() const
{
	return ItemType::HealItem;
}

std::shared_ptr<BaseItem> HealItem::getSharedPtr()
{
	return std::make_shared<HealItem>(*this);
}
