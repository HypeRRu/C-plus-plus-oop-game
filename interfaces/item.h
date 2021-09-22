#ifndef ITEM_H
#define ITEM_H

class Cell;

class Item
{
public:
	virtual void attach(Cell& holder) = 0;
	virtual void onAdd() = 0;
	virtual void onPickUp() = 0;
	virtual void destroy() = 0;
};

#endif