#include "../../inc/views/weapon_item_view.h"

WeaponItemView::WeaponItemView(size_t x, size_t y): BaseItemView(x, y)
{}

const std::string WeaponItemView::getTextureAlias() const
{
	return "weapon_item";
}
