#ifndef BASE_ITEM_H
#define BASE_ITEM_H

#include <memory>

#include "../interfaces/item.h"
#include "../interfaces/drawable.h"
#include "../actions/base_observed.h"
#include "../actions/action_add_item.h"
#include "../cells/cell.h"
#include "../actions/action_pick_item.h"
#include "../actions/action_delete_item.h"
#include "../entities/base_entity.h"

class BaseItem: 
	public Item,
	public Drawable,
	public BaseObserved
{
public:
	BaseItem(size_t x, size_t y);

	bool onAdd();
	virtual bool onPickUp(BaseEntity& entity) = 0;
	void destroy();

	virtual const std::string getTextureAlias() const = 0;
	const size_t getX() const;
	const size_t getY() const;

	virtual std::shared_ptr<BaseItem> getSharedPtr() = 0;
protected:
	size_t x;
	size_t y;
};

#endif