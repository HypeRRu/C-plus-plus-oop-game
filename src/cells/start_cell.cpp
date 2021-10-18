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
