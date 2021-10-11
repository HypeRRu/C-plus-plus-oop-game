#include "../../inc/cells/cell.h"
#include "../../inc/items/base_item.h"

Cell::Cell(size_t x, size_t y, bool wall) : x{x}, y{y}, wall{wall}
{}

CellType Cell::getType()
{
	return CellType::RegularCell;
}

Cell::Cell(const Cell& other): x{other.x}, y{other.y}, wall{other.wall}
{
	if (other.item.get())
		item = other.item.get()->getSharedPtr();
}

Cell::Cell(Cell&& other): x{other.x}, y{other.y}, wall{other.wall}
{
	std::swap(this->item, other.item);
}

Cell::Cell(Cell* other): x{other->x}, y{other->y}, wall{other->wall}
{
	if (other->item.get())
		item = other->item.get()->getSharedPtr();
}

Cell& Cell::operator =(const Cell& other)
{
	if (&other == this)
		return *this;

	this->x    = other.x;
	this->y    = other.y;
	this->wall = other.wall;
	if (other.item.get())
		item = other.item.get()->getSharedPtr();

	return *this;
}

Cell& Cell::operator =(Cell&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->x, other.x);
	std::swap(this->y, other.y);
	std::swap(this->wall, other.wall);
	std::swap(this->item, other.item);

	return *this;
}

void Cell::setItem(std::shared_ptr<BaseItem> _item)
{
	this->item = _item;
	if (_item)
		this->item->onAdd();
}

const size_t Cell::getX() const
{
	return this->x;
}

const size_t Cell::getY() const
{
	return this->y;
}

bool   Cell::getHasWall() const
{
	return this->wall;
}

void Cell::toggleWall()
{
	this->wall = !this->wall;
}

BaseItem& Cell::getItem() const
{
	return *this->item.get();
}

std::unique_ptr<Cell> Cell::createUniquePtr()
{
	return std::make_unique<Cell>(*this);
}

const std::string Cell::getTextureAlias() const
{
	if (this->wall)
		return "cell_wall";
	return "cell_regular";
}
