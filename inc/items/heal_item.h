#ifndef HEAL_ITEM_H
#define HEAL_ITEM_H

#include "../items/base_item.h"
#include "../views/heal_item_view.h"

class HealItem: public BaseItem
{
public:
	HealItem(
		size_t x,
		size_t y,
		size_t healing_amount = 50
	);
	~HealItem() = default;

	bool onPickUp(BaseEntity& entity);
	const int getEffect() const;

	ItemType getItemType() const;
	std::shared_ptr<BaseItem> getSharedPtr();
};

#endif
