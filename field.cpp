#include "field.h"

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
{}

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

const Cell& Field::getCell(size_t x, size_t y) const
{
	if (x < 0 || y < 0 || x >= this->width || y >= this->height) 
		throw std::runtime_error("Координаты не должны выходить за границы поля!");

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
		cells[i] = std::make_unique<cell_ptr[]>(this->height);
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