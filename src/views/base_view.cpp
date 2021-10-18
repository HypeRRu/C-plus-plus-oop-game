#include "../../inc/views/base_view.h"

BaseView::BaseView(size_t x, size_t y): x{x}, y{y}
{}

const size_t BaseView::getX() const
{
	return this->x;
}
const size_t BaseView::getY() const
{
	return this->y;
}