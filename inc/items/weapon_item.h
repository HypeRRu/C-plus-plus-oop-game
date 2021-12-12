#ifndef WEAPON_ITEM_H
#define WEAPON_ITEM_H

#include "../items/base_item.h"
#include "../views/weapon_item_view.h"

class ItemSaver;

class WeaponItem: public BaseItem
{
public:
	WeaponItem(
		size_t x,
		size_t y,
		size_t damage_increase = 50
	);
	~WeaponItem() = default;

	bool onPickUp(BaseEntity& entity);
	const int getEffect() const;

	ItemType getItemType() const;
	std::shared_ptr<BaseItem> getSharedPtr();

	std::shared_ptr<ItemSaver> createSaver() const;
};

#endif
