#ifndef START_CELL_VIEW_H
#define START_CELL_VIEW_H

#include "cell_view.h"

class StartCellView: public CellView
{
public:
	StartCellView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
