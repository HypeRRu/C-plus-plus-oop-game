#ifndef END_H
#define END_H

#include "cell.h"

class EndCell: public Cell
{
public:
	EndCell(size_t x, size_t y);
	~EndCell() = default;

	CellType getType();

	const std::string getTextureAlias() const;

	std::unique_ptr<Cell> createUniquePtr();
};

#endif
