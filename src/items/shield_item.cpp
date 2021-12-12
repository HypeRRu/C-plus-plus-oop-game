#include "../../inc/items/shield_item.h"
#include "../../inc/saves/item_saver.h"

ShieldItem::ShieldItem(
	size_t x,
	size_t y,
	size_t shield_increase
) : BaseItem(x, y)
{
	this->setView(std::make_shared<ShieldItemView>(x, y));
	this->effect = shield_increase;
}

bool ShieldItem::onPickUp(BaseEntity& entity)
{
	entity.changeShield(this->effect);
	this->destroy();
	return true;
}

const int ShieldItem::getEffect() const
{
	return this->effect;
}

ItemType ShieldItem::getItemType() const
{
	return ItemType::ShieldItem;
}

std::shared_ptr<BaseItem> ShieldItem::getSharedPtr()
{
	return std::make_shared<ShieldItem>(*this);
}

std::shared_ptr<ItemSaver> ShieldItem::createSaver() const
{
	return std::make_shared<ItemSaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->effect,
		"ShieldItem"
	);
}
