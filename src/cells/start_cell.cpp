#include "../../inc/cells/start_cell.h"

StartCell::StartCell(size_t x, size_t y) : Cell{x, y, false}
{
	this->setView(std::make_shared<StartCellView>(x, y));
}

CellType StartCell::getType()
{
	return CellType::StartCell;
}

std::unique_ptr<Cell> StartCell::createUniquePtr()
{
	return std::make_unique<StartCell>(*this);
}

std::string StartCell::getCurrentState(
	const std::string& line_offset, 
	const std::string& cell_type
) const
{
	return Cell::getCurrentState(line_offset, "StartCell");
}
