#ifndef CELL_H
#define CELL_H

#include <memory>
#include <vector>
#include <string>

#include "../interfaces/drawable.h"

enum class CellType {
	RegularCell,
	StartCell,
	EndCell
};

class BaseItem;

class Cell: virtual public Drawable
{
public:
	Cell(size_t x, size_t y, bool wall = false);
	virtual ~Cell() = default;

	virtual CellType getType();

	Cell(const Cell& other);
	Cell(Cell&& other);
	Cell(Cell* other);

	Cell& operator =(const Cell& other);
	Cell& operator =(Cell&& other);

	void setItem(std::shared_ptr<BaseItem> _item);

	BaseItem& getItem() const;
	const size_t getX() const;
	const size_t getY() const;
	bool   getHasWall() const;

	void toggleWall();

	virtual const std::string getTextureAlias() const;

	virtual std::unique_ptr<Cell> createUniquePtr();
protected:
	size_t x, y;
	bool wall;
	std::shared_ptr<BaseItem> item;
};

#endif
