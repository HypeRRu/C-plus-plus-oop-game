#include "../../inc/views/cell_view.h"

CellView::CellView(size_t x, size_t y, bool has_wall): BaseView(x, y)
{
	this->has_wall = has_wall;
}

const std::string CellView::getTextureAlias() const
{
	if (this->has_wall)
		return "cell_wall";
	return "cell_regular";
}