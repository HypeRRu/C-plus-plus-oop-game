#ifndef END_H
#define END_H

#include "cell.h"
#include "../views/end_cell_view.h"

class EndCell: public Cell
{
public:
	EndCell(size_t x, size_t y);
	~EndCell() = default;

	CellType getType();

	std::string getCurrentState(
		const std::string& line_offset = "",
		const std::string& cell_type = ""
	) const;

	std::unique_ptr<Cell> createUniquePtr();
};

#endif
