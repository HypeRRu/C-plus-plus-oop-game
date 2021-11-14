#ifndef COIN_ITEM_H
#define COIN_ITEM_H

#include "../items/base_item.h"
#include "../views/coin_item_view.h"

class CoinItem: public BaseItem
{
public:
	CoinItem(
		size_t x,
		size_t y,
		size_t amount = 1
	);

	bool onPickUp(BaseEntity& entity);
	const int getEffect() const;

	ItemType getItemType() const;
	std::shared_ptr<BaseItem> getSharedPtr();
};

#endif