#include "../../inc/items/weapon_item.h"

WeaponItem::WeaponItem(
	size_t x,
	size_t y,
	size_t damage_increase
) : BaseItem(x, y), damage_increase{damage_increase}
{}

bool WeaponItem::onPickUp(BaseEntity& entity)
{
	entity.increaseDamage(this->damage_increase);
	this->destroy();
	return true;
}

const std::string WeaponItem::getTextureAlias() const
{
	return "weapon_item";
}

const size_t WeaponItem::getDamageIncrease() const
{
	return this->damage_increase;
}

std::shared_ptr<BaseItem> WeaponItem::getSharedPtr()
{
	return std::make_shared<WeaponItem>(*this);
}
