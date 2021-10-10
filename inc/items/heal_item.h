#ifndef HEAL_ITEM_H
#define HEAL_ITEM_H

#include "../items/base_item.h"

class HealItem: public BaseItem
{
public:
	HealItem(
		size_t x,
		size_t y,
		size_t healing_amount = 3
	);

	bool onPickUp(BaseEntity& entity);
	const std::string getTextureAlias() const;
	const size_t getHealingAmount() const;

	std::shared_ptr<BaseItem> getSharedPtr();
protected:
	size_t healing_amount = 3;
};

#endif
