#ifndef SHIELD_ITEM_H
#define SHIELD_ITEM_H

#include "../items/base_item.h"
#include "../views/shield_item_view.h"

class ItemSaver;

class ShieldItem: public BaseItem
{
public:
	ShieldItem(
		size_t x,
		size_t y,
		size_t shield_increase = 50
	);
	~ShieldItem() = default;

	bool onPickUp(BaseEntity& entity);
	const int getEffect() const;

	ItemType getItemType() const;
	std::shared_ptr<BaseItem> getSharedPtr();

	std::shared_ptr<ItemSaver> createSaver() const;
};

#endif
