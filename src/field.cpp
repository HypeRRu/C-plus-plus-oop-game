#include "../inc/field.h"
#include "../inc/actions/game_observer.h"

Field::Field(size_t width, size_t height)
{
	if (width <= 0 || height <= 0) 
		throw std::runtime_error("Длина и ширина должны быть положительными числами!");
	this->width = width;
	this->height = height;

	cells = std::make_unique<cell_row[]>(this->height);
	for (size_t i = 0; i < this->height; i++)
	{
		cells[i] = std::make_unique<cell_ptr[]>(this->width);
	}
}

Field::Field(const Field& other) : Field(other.width, other.height)
{
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			this->setCell(x, y, other.cells[y][x].get());
		}
	}
}

Field::Field(Field&& other) : width{other.width}, height{other.height}
{
	cells = std::move(other.cells);
}

void Field::setCell(size_t x, size_t y, Cell *cell)
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height) 
		throw std::runtime_error("Координаты не должны выходить за границы поля!");
	cells[y][x] = cell->createUniquePtr();
}

bool Field::onCellsAdded()
{
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			ActionAddDrawable act(this->getCell(x, y), true);
			this->getObserver().handleAction(act);
		}
	}
	return true;
}

Cell& Field::getCell(size_t x, size_t y) const
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height) 
		return *this->cells[0][0].get();

	return *this->cells[y][x].get();
}

Field& Field::operator =(const Field& other)
{
	if (&other == this)
		return *this;

	this->width = other.width;
	this->height = other.height;

	cells = std::make_unique<cell_row[]>(this->height);
	for (size_t i = 0; i < this->height; i++)
	{
		cells[i] = std::make_unique<cell_ptr[]>(this->width);
	}
	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			this->setCell(x, y, other.cells[y][x].get());
		}
	}

	return *this;
}

Field& Field::operator =(Field&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->width, other.width);
	std::swap(this->height, other.height);
	std::swap(this->cells, other.cells);

	return *this;
}

size_t Field::getHeight() const
{
	return this->height;
}

size_t Field::getWidth() const
{
	return this->width;
}

CellsIterator& Field::createIterator()
{
	std::shared_ptr<CellsIterator> iter = 
		std::make_shared<CellsIterator>(
			width,
			height,
			this->cells
		);
	return *iter.get();
}

void Field::setStart(const std::pair<size_t, size_t>& start)
{
	this->start.first  = start.first;
	this->start.second = start.second;
}

void Field::setEnd(const std::pair<size_t, size_t>& end)
{
	this->end.first  = end.first;
	this->end.second = end.second;
}


void Field::setStart(size_t x, size_t y)
{
	this->start.first  = x;
	this->start.second = y;
}

void Field::setEnd(size_t x, size_t y)
{
	this->end.first  = x;
	this->end.second = y;
}

const std::pair<size_t, size_t>& Field::getStart() const
{
	return this->start;
}

const std::pair<size_t, size_t>& Field::getEnd() const
{
	return this->end;
}
