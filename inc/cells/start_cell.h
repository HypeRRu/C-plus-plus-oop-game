#ifndef STARTCELL_H
#define STARTCELL_H

#include "cell.h"
#include "../views/start_cell_view.h"

class CellSaver;

class StartCell: public Cell
{
public:
	StartCell(size_t x, size_t y);
	~StartCell() = default;

	CellType getType();

	std::shared_ptr<CellSaver> createSaver() const;

	std::unique_ptr<Cell> createUniquePtr();
};

#endif
