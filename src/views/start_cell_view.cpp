#include "../../inc/views/start_cell_view.h"

StartCellView::StartCellView(size_t x, size_t y): CellView(x, y)
{}

const std::string StartCellView::getTextureAlias() const
{
	return "cell_start";
}
