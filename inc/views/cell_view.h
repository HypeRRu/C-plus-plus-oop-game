#ifndef CELL_VIEW_H
#define CELL_VIEW_H

#include "base_view.h"

class CellView: public BaseView
{
public:
	CellView(size_t x = 0, size_t y = 0, bool has_wall = false);
	virtual const std::string getTextureAlias() const;
protected:
	bool has_wall;
};

#endif
