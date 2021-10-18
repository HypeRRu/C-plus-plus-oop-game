#ifndef CELL_H
#define CELL_H

#include <memory>
#include <vector>
#include <string>

#include "../views/cell_view.h"
#include "../views/base_drawable.h"

enum class CellType {
	RegularCell,
	StartCell,
	EndCell
};

class BaseItem;
class BaseEnemy;

class Cell: public BaseDrawable
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
	void setEnemy(std::shared_ptr<BaseEnemy> _enemy);

	std::shared_ptr<BaseEnemy> getEnemy() const;
	BaseItem& getItem() const;
	const size_t getX() const;
	const size_t getY() const;
	bool   getHasWall() const;

	void toggleWall();

	virtual std::unique_ptr<Cell> createUniquePtr();
protected:
	size_t x, y;
	bool wall;
	std::shared_ptr<BaseItem> item;
	std::shared_ptr<BaseEnemy> enemy;
};

#endif
