#ifndef CELL_H
#define CELL_H

#include <memory>
#include <vector>
#include <string>

#include "../views/cell_view.h"
#include "../views/base_drawable.h"
#include "../actions/base_observed.h"

enum class CellType {
	RegularCell,
	StartCell,
	EndCell
};

class BaseItem;
class BaseEnemy;
class CellSaver;

class Cell: public BaseDrawable, public BaseObserved
{
public:
	Cell(size_t x, size_t y, bool wall = false);
	virtual ~Cell();

	virtual CellType getType();

	Cell(const Cell& other);
	Cell(Cell&& other);
	Cell(Cell* other);

	Cell& operator =(const Cell& other);
	Cell& operator =(Cell&& other);

	void setItem(std::shared_ptr<BaseItem> _item = nullptr);
	void setEnemy(std::shared_ptr<BaseEnemy> _enemy = nullptr);

	std::weak_ptr<BaseEnemy> getEnemy() const;
	std::weak_ptr<BaseItem> getItem() const;
	const size_t getX() const;
	const size_t getY() const;
	bool   getHasWall() const;

	void toggleWall();
	virtual std::shared_ptr<CellSaver> createSaver() const;

	virtual std::unique_ptr<Cell> createUniquePtr();
protected:
	size_t x, y;
	bool wall;
	std::shared_ptr<BaseItem> item;
	std::shared_ptr<BaseEnemy> enemy;
};

#endif
