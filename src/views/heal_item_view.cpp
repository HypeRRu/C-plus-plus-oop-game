#include "../../inc/views/heal_item_view.h"

HealItemView::HealItemView(size_t x, size_t y): BaseItemView(x, y)
{}

const std::string HealItemView::getTextureAlias() const
{
	return "heal_item";
}
