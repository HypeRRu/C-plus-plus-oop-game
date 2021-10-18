#include "../../inc/items/heal_item.h"

HealItem::HealItem(
	size_t x,
	size_t y,
	size_t healing_amount
) : BaseItem(x, y), healing_amount{healing_amount}
{
	this->setView(std::make_shared<HealItemView>(x, y));
}

bool HealItem::onPickUp(BaseEntity& entity)
{
	entity.changeHealth(this->healing_amount);
	this->destroy();
	return true;
}

const std::string HealItem::getTextureAlias() const
{
	return "heal_item";
}

const size_t HealItem::getHealingAmount() const
{
	return this->healing_amount;
}

std::shared_ptr<BaseItem> HealItem::getSharedPtr()
{
	return std::make_shared<HealItem>(*this);
}
