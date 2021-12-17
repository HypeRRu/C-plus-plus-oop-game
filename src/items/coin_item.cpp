#include "../../inc/items/coin_item.h"
#include "../../inc/saves/item_saver.h"

#include <iostream>
CoinItem::CoinItem(
	size_t x,
	size_t y,
	size_t amount
) : BaseItem(x, y)
{
	this->setView(std::make_shared<CoinItemView>(x, y));
	this->effect = amount;
}

bool CoinItem::onPickUp(BaseEntity& entity)
{
	entity.changeMoneyPicked(this->effect);
	this->destroy();
	return true;
}

const int CoinItem::getEffect() const
{
	return this->effect;
}

ItemType CoinItem::getItemType() const
{
	return ItemType::CoinItem;
}

std::shared_ptr<BaseItem> CoinItem::getSharedPtr()
{
	return std::make_shared<CoinItem>(*this);
}

std::shared_ptr<ItemSaver> CoinItem::createSaver() const
{
	return std::make_shared<ItemSaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->effect,
		"CoinItem"
	);
}
