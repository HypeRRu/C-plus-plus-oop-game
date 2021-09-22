#ifndef STARTCELL_H
#define STARTCELL_H

#include "cell.h"

class StartCell: public Cell
{
public:
	StartCell(size_t x, size_t y);
	~StartCell() = default;

	CellType getType();

	std::string getTextureAlias() const;

	std::unique_ptr<Cell> createUniquePtr();
};

#endif