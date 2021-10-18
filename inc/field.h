#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <stdexcept>

#include "cells/cell.h"
#include "cells/start_cell.h"
#include "cells/end_cell.h"
#include "utils/cells_iterator.h"
#include "actions/base_observed.h"
#include "actions/action_add_drawable.h"

class Field: public BaseObserved
{
public:
	Field(size_t width, size_t height);
	~Field() = default;

	Field(const Field& other);
	Field(Field&& other);

	void setCell(size_t x, size_t y, Cell *cell);	
	bool onCellsAdded();

	Field& operator =(const Field& other);
	Field& operator =(Field&& other);

	size_t getWidth() const;
	size_t getHeight() const;
<<<<<<< HEAD
	const Cell&  getCell(size_t x, size_t y) const;
=======
	Cell&  getCell(size_t x, size_t y) const;
<<<<<<< HEAD:inc/field.h

	CellsIterator& createIterator();

	void setStart(const std::pair<size_t, size_t>& start);
	void setEnd(const std::pair<size_t, size_t>& end);
	void setStart(size_t x, size_t y);	
	void setEnd(size_t x, size_t y);

	const std::pair<size_t, size_t>& getStart() const;
	const std::pair<size_t, size_t>& getEnd() const;
=======
>>>>>>> ac1c973d8b23976949ff75730bff368231784f0c
>>>>>>> master:field.h
private:
	using cell_ptr = std::unique_ptr<Cell>;
	using cell_row = std::unique_ptr<cell_ptr[]>;

	size_t width;
	size_t height;
	std::unique_ptr<cell_row[]> cells;

	std::pair<size_t, size_t> start;
	std::pair<size_t, size_t> end;
};

#endif
