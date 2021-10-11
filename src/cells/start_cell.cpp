#include "../../inc/cells/start_cell.h"

StartCell::StartCell(size_t x, size_t y) : Cell{x, y, false}
{}

CellType StartCell::getType()
{
	return CellType::StartCell;
}

std::unique_ptr<Cell> StartCell::createUniquePtr()
{
	return std::make_unique<StartCell>(*this);
}

const std::string StartCell::getTextureAlias() const
{
	return "cell_start";
}
