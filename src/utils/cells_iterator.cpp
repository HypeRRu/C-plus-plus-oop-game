#include "../../inc/utils/cells_iterator.h"

CellsIterator::CellsIterator(
	size_t object_w,
	size_t object_h,
	Field& _field
) : cursor_x{0}, 
	cursor_y{0},
	object_w{object_w},
	object_h{object_h},
	field{_field}
{}

void CellsIterator::first()
{
	this->cursor_x = 0;
	this->cursor_y = 0;
}

void CellsIterator::next()
{
	if (!this->isDone())
		this->cursor_x++;
	if (this->cursor_x == this->object_w)
	{
		this->cursor_x = 0;
		this->cursor_y++;
	}
}

bool CellsIterator::isDone() const
{
	return (this->cursor_y == this->object_h);
}

Cell& CellsIterator::currentItem() const
{
	return this->field.getCell(cursor_x, cursor_y);
	// return *this->cells[cursor_y][cursor_x].get();
}
