#include "end_cell.h"

EndCell::EndCell(size_t x, size_t y) : Cell{x, y, false}
{}

CellType EndCell::getType()
{
	return CellType::EndCell;
}

std::unique_ptr<Cell> EndCell::createUniquePtr()
{
	return std::make_unique<EndCell>(*this);
}

std::string EndCell::getTextureAlias() const
{
	return "cell_end";
}