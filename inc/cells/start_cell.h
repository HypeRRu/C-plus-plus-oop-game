#ifndef STARTCELL_H
#define STARTCELL_H

#include "cell.h"
#include "../views/start_cell_view.h"

class StartCell: public Cell
{
public:
	StartCell(size_t x, size_t y);
	~StartCell() = default;

	CellType getType();

	std::string getCurrentState(
		const std::string& line_offset = "",
		const std::string& cell_type = ""
	) const;

	std::unique_ptr<Cell> createUniquePtr();
};

#endif
