#ifndef ITEM_H
#define ITEM_H

class Action;
class BaseEntity;

enum class ItemType
{
	HealItem,
	ShieldItem,
	WeaponItem,
	CoinItem
};

class Item
{
public:
	virtual bool onPickUp(BaseEntity& entity) = 0;
	virtual bool onAdd() = 0;
	virtual void destroy() = 0;
	virtual const int getEffect() const = 0;
	virtual ItemType getItemType() const = 0;
	virtual ~Item() = default;
};

#endif
