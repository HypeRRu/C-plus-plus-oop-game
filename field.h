#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include "cells/cell.h"
#include "cells/start_cell.h"
#include "cells/end_cell.h"
#include <stdexcept>

class Field
{
public:
	Field(size_t width, size_t height);
	~Field() = default;

	Field(const Field& other);
	Field(Field&& other);

	void setCell(size_t x, size_t y, Cell *cell);	

	Field& operator =(const Field& other);
	Field& operator =(Field&& other);

	size_t getWidth() const;
	size_t getHeight() const;
	const Cell&  getCell(size_t x, size_t y) const;
private:
	using cell_ptr = std::unique_ptr<Cell>;
	using cell_row = std::unique_ptr<cell_ptr[]>;

	size_t width;
	size_t height;
	std::unique_ptr<cell_row[]> cells;
};

#endif