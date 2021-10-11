#ifndef SHIELD_ITEM_H
#define SHIELD_ITEM_H

#include "../items/base_item.h"

class ShieldItem: public BaseItem
{
public:
	ShieldItem(
		size_t x,
		size_t y,
		size_t shield_increase = 50
	);

	bool onPickUp(BaseEntity& entity);
	const std::string getTextureAlias() const;
	const size_t getShieldIncrease() const;

	std::shared_ptr<BaseItem> getSharedPtr();
protected:
	size_t shield_increase = 3;
};

#endif
