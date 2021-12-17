#include "../../inc/cells/end_cell.h"
#include "../../inc/saves/cell_saver.h"

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

std::shared_ptr<CellSaver> EndCell::createSaver() const
{
	return std::make_shared<CellSaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->wall,
		this->getEnemy(),
		this->getItem(),
		"EndCell"
	);
}
