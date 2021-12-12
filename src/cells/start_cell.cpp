#include "../../inc/cells/start_cell.h"
#include "../../inc/saves/cell_saver.h"

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

std::shared_ptr<CellSaver> StartCell::createSaver() const
{
	return std::make_shared<CellSaver>(
		std::pair<size_t, size_t>{this->x, this->y},
		this->wall,
		this->getEnemy(),
		this->getItem(),
		"StartCell"
	);
}
