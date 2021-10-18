#ifndef WEAPON_ITEM_H
#define WEAPON_ITEM_H

#include "../items/base_item.h"
#include "../views/weapon_item_view.h"

class WeaponItem: public BaseItem
{
public:
	WeaponItem(
		size_t x,
		size_t y,
		size_t damage_increase = 50
	);

	bool onPickUp(BaseEntity& entity);
	const std::string getTextureAlias() const;
	const size_t getDamageIncrease() const;

	std::shared_ptr<BaseItem> getSharedPtr();
protected:
	size_t damage_increase;
};

#endif
