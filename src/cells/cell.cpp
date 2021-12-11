#include "../../inc/cells/cell.h"
#include "../../inc/items/base_item.h"
#include "../../inc/entities/base_enemy.h"

Cell::Cell(size_t x, size_t y, bool wall) : x{x}, y{y}, wall{wall}
{
	this->setView(std::make_shared<CellView>(x, y, wall));
}

Cell::~Cell()
{
	this->item.reset();
	this->enemy.reset();
}

CellType Cell::getType()
{
	return CellType::RegularCell;
}

Cell::Cell(const Cell& other): BaseDrawable(other),
	x{other.x}, y{other.y}, wall{other.wall}
{
	if (other.item.get())
		item = other.item.get()->getSharedPtr();
	if (other.enemy.get())
		enemy = other.enemy.get()->getSharedPtr();
}

Cell::Cell(Cell&& other): BaseDrawable(other),
	x{other.x}, y{other.y}, wall{other.wall}
{
	std::swap(this->item, other.item);
	std::swap(this->enemy, other.enemy);
	this->setView(other.view);
}

Cell::Cell(Cell* other): BaseDrawable(*other),
	x{other->x}, y{other->y}, wall{other->wall}
{
	if (other->item.get())
		item = other->item.get()->getSharedPtr();
	if (other->enemy.get())
		enemy = other->enemy.get()->getSharedPtr();
}

Cell& Cell::operator =(const Cell& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	this->x    = other.x;
	this->y    = other.y;
	this->wall = other.wall;

	if (other.item.get())
		item = other.item.get()->getSharedPtr();
	if (other.enemy.get())
		enemy = other.enemy.get()->getSharedPtr();

	return *this;
}

Cell& Cell::operator =(Cell&& other)
{
	if (&other == this)
		return *this;

	BaseDrawable::operator=(other);
	std::swap(this->x, other.x);
	std::swap(this->y, other.y);
	std::swap(this->wall, other.wall);
	std::swap(this->item, other.item);
	std::swap(this->enemy, other.enemy);

	return *this;
}

#include <iostream>
void Cell::setItem(std::shared_ptr<BaseItem> _item)
{
	if (!_item.get())
		this->item.reset();
	else
		this->item = _item;
}

void Cell::setEnemy(std::shared_ptr<BaseEnemy> _enemy)
{
	if(!_enemy.get())
		this->enemy.reset();
	else
		this->enemy = _enemy;
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

std::weak_ptr<BaseItem> Cell::getItem() const
{
	return this->item;
}

std::weak_ptr<BaseEnemy> Cell::getEnemy() const
{
	return this->enemy;
}

std::unique_ptr<Cell> Cell::createUniquePtr()
{
	return std::make_unique<Cell>(*this);
}

std::string Cell::getCurrentState(
	const std::string& line_offset, 
	const std::string& cell_type
) const
{
	std::stringstream buffer;
	std::string content_offset = line_offset + "\t";
	buffer << line_offset << "[" << std::endl;
	buffer << content_offset << "type=" << cell_type << std::endl;
	buffer << content_offset << "position=(" << this->x << "; " << this->y << ")" << std::endl;
	buffer << content_offset << "wall=" << this->getHasWall() << std::endl;
	if (this->enemy.get())
	{
		buffer << content_offset << "entity=" << std::endl;
	}
	buffer << line_offset << "]" << std::endl;

	return buffer.str();
}
