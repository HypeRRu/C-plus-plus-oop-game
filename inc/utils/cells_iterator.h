#ifndef CELLS_ITERATOR_H
#define CELLS_ITERATOR_H

#include "../cells/cell.h"
#include "../interfaces/iterator.h"
#include <memory>

using cell_ptr = std::unique_ptr<Cell>;
using cell_row = std::unique_ptr<cell_ptr[]>;

class CellsIterator : public Iterator<Cell>
{
public:
	CellsIterator(
		size_t object_w,
		size_t object_h,
		std::unique_ptr<cell_row[]>& iterable
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

	std::unique_ptr<cell_row[]>& cells;
};

#endif
