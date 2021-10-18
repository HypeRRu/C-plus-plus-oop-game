#ifndef END_CELL_VIEW_H
#define END_CELL_VIEW_H

#include "cell_view.h"

class EndCellView: public CellView
{
public:
	EndCellView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
