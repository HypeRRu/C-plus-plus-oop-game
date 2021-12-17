#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <stdexcept>
#include <sstream>
#include <string>

#include "cells/cell.h"
#include "cells/start_cell.h"
#include "cells/end_cell.h"
#include "actions/base_observed.h"
#include "actions/action_add_drawable.h"
#include "exceptions/game_logic_error.h"

#include "saves/field_saver.h"

class FieldSaver;

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
	Cell&  getCell(size_t x, size_t y) const;

	void setStart(const std::pair<size_t, size_t>& start);
	void setEnd(const std::pair<size_t, size_t>& end);
	void setStart(size_t x, size_t y);	
	void setEnd(size_t x, size_t y);

	const std::pair<size_t, size_t>& getStart() const;
	const std::pair<size_t, size_t>& getEnd() const;

	// save field state
	std::shared_ptr<FieldSaver> createSaver() const;

	class iterator
	{
	public:
		iterator(
			Field& _field, 
			std::pair<size_t, size_t> cursor_position = {0, 0}
		);
		iterator& operator ++();
		iterator operator ++(int);
		bool operator ==(const iterator& other) const;
		bool operator !=(const iterator& other) const;
		Cell& operator *() const;
		Cell* operator ->() const;
	protected:
		Field& field;
		size_t cursor_x;
		size_t cursor_y;
	};
	iterator begin();
	iterator end();
private:
	using cell_ptr = std::unique_ptr<Cell>;
	using cell_row = std::unique_ptr<cell_ptr[]>;

	size_t width;
	size_t height;
	std::unique_ptr<cell_row[]> cells;

	std::pair<size_t, size_t> start_cell;
	std::pair<size_t, size_t> end_cell;
};

#endif
