#include "../../inc/views/end_cell_view.h"

EndCellView::EndCellView(size_t x, size_t y): CellView(x, y)
{}

const std::string EndCellView::getTextureAlias() const
{
	return "cell_end";
}
