#include "../../inc/views/shield_item_view.h"

ShieldItemView::ShieldItemView(size_t x, size_t y): BaseItemView(x, y)
{}

const std::string ShieldItemView::getTextureAlias() const
{
	return "shield_item";
}
