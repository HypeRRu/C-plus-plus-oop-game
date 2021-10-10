#ifndef ITEM_H
#define ITEM_H

// class Cell;
class Action;
class BaseEntity;

class Item
{
public:
	// virtual void attach(Cell& _holder) = 0;
	virtual bool onPickUp(BaseEntity& entity) = 0;
	virtual void destroy() = 0;
	virtual ~Item() = default;
	/*virtual void onAdd() = 0;
	virtual void onPickUp() = 0;*/	


};

#endif