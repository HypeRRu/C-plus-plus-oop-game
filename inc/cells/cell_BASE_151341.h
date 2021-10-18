#ifndef CELL_H
#define CELL_H

#include <memory>
#include <vector>
#include <string>

#include "../interfaces/item.h"

enum class CellType {
	RegularCell,
	StartCell,
	EndCell
};

class Cell
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

	size_t getX() const;
	size_t getY() const;
	bool   getHasWall() const;

	void toggleWall();

	virtual std::string getTextureAlias() const;

	virtual std::unique_ptr<Cell> createUniquePtr();
protected:
	using item_ptr = std::shared_ptr<Item>;

	size_t x, y;
	bool wall;
	std::vector<item_ptr> items;
};

#endif