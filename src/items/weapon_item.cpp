#include "../../inc/items/weapon_item.h"

WeaponItem::WeaponItem(
	size_t x,
	size_t y,
	size_t damage_increase
) : BaseItem(x, y)
{
	this->setView(std::make_shared<WeaponItemView>(x, y));
	this->effect = damage_increase;
}

bool WeaponItem::onPickUp(BaseEntity& entity)
{
	entity.changeDamage(this->effect);
	this->destroy();
	return true;
}

const int WeaponItem::getEffect() const
{
	return this->effect;
}

ItemType WeaponItem::getItemType() const
{
	return ItemType::WeaponItem;
}

std::shared_ptr<BaseItem> WeaponItem::getSharedPtr()
{
	return std::make_shared<WeaponItem>(*this);
}
