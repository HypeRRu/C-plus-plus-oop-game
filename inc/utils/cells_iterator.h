#ifndef CELLS_ITERATOR_H
#define CELLS_ITERATOR_H

#include "../cells/cell.h"
#include "../field.h"
#include "../interfaces/iterator.h"
#include <memory>

class Field;

class CellsIterator : public Iterator<Cell>
{
public:
	CellsIterator(
		size_t object_w,
		size_t object_h,
		Field& _field
	);
	void first();
	void next();
	bool isDone() const;
	Cell& currentItem() const;
private:
	size_t cursor_x;
	size_t cursor_y;

	size_t object_w;
	size_t object_h;

	Field& field;
};

#endif
