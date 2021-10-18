#include "../../inc/items/shield_item.h"

ShieldItem::ShieldItem(
	size_t x,
	size_t y,
	size_t shield_increase
) : BaseItem(x, y), shield_increase{shield_increase}
{
	this->setView(std::make_shared<ShieldItemView>(x, y));
}

bool ShieldItem::onPickUp(BaseEntity& entity)
{
	entity.changeShield(this->shield_increase);
	this->destroy();
	return true;
}

const std::string ShieldItem::getTextureAlias() const
{
	return "shield_item";
}

const size_t ShieldItem::getShieldIncrease() const
{
	return this->shield_increase;
}

std::shared_ptr<BaseItem> ShieldItem::getSharedPtr()
{
	return std::make_shared<ShieldItem>(*this);
}
