#ifndef BASE_ITEM_H
#define BASE_ITEM_H

#include <memory>

#include "../interfaces/item.h"
#include "../actions/base_observed.h"
#include "../actions/action_add_drawable.h"
#include "../cells/cell.h"
#include "../actions/action_pick_item.h"
#include "../actions/action_delete_item.h"
#include "../entities/base_entity.h"
#include "../views/base_drawable.h"

class BaseItem: 
	public Item,
	public BaseDrawable,
	public BaseObserved
{
public:
	BaseItem(size_t x, size_t y);
	virtual ~BaseItem() = default;

	virtual bool onPickUp(BaseEntity& entity) = 0;
	bool onAdd();
	void destroy();
	virtual const int getEffect() const = 0;
	
	const size_t getX() const;
	const size_t getY() const;

	virtual std::shared_ptr<BaseItem> getSharedPtr() = 0;
	virtual ItemType getItemType() const = 0;

	BaseItem(const BaseItem& other);
	BaseItem(BaseItem&& other);
	BaseItem& operator =(const BaseItem& other);
	BaseItem& operator =(BaseItem&& other);
protected:
	size_t x;
	size_t y;
	int effect;
};

#endif
