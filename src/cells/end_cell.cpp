#include "../../inc/cells/end_cell.h"

EndCell::EndCell(size_t x, size_t y) : Cell{x, y, false}
{
	this->setView(std::make_shared<EndCellView>(x, y));
}

CellType EndCell::getType()
{
	return CellType::EndCell;
}

std::unique_ptr<Cell> EndCell::createUniquePtr()
{
	return std::make_unique<EndCell>(*this);
}

std::string EndCell::getCurrentState(
	const std::string& line_offset, 
	const std::string& cell_type
) const
{
	return Cell::getCurrentState(line_offset, "EndCell");
}
