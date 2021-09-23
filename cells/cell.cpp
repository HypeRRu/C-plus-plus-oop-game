#include "cell.h"

Cell::Cell(size_t x, size_t y, bool wall) : x{x}, y{y}, wall{wall}
{}

CellType Cell::getType()
{
	return CellType::RegularCell;
}

Cell::Cell(const Cell& other): x{other.x}, y{other.y}, wall{other.wall}
{
	for (size_t i = 0; i < other.items.size(); i++)
		this->items.push_back(other.items.at(i));
}

Cell::Cell(Cell&& other): x{other.x}, y{other.y}, wall{other.wall}
{
	std::swap(this->items, other.items);
}

Cell::Cell(Cell* other): x{other->x}, y{other->y}, wall{other->wall}
{
	for (size_t i = 0; i < other->items.size(); i++)
		this->items.push_back(other->items.at(i));
}

Cell& Cell::operator =(const Cell& other)
{
	if (&other == this)
		return *this;

	this->x    = other.x;
	this->y    = other.y;
	this->wall = other.wall;
	for (size_t i = 0; i < other.items.size(); i++)
		this->items.push_back(other.items.at(i));

	return *this;
}

Cell& Cell::operator =(Cell&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->x, other.x);
	std::swap(this->y, other.y);
	std::swap(this->wall, other.wall);
	std::swap(this->items, other.items);

	return *this;
}

size_t Cell::getX() const
{
	return this->x;
}

size_t Cell::getY() const
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

std::unique_ptr<Cell> Cell::createUniquePtr()
{
	return std::make_unique<Cell>(this);
}

std::string Cell::getTextureAlias() const
{
	if (this->wall)
		return "cell_wall";
	return "cell_regular";
}