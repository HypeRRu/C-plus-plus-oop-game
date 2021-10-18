#ifndef ITEM_H
#define ITEM_H

class Action;
class BaseEntity;

class Item
{
public:
	virtual bool onPickUp(BaseEntity& entity) = 0;
	virtual bool onAdd() = 0;
	virtual void destroy() = 0;
	virtual ~Item() = default;
};

#endif
