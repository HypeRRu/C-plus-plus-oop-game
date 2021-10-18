#ifndef WEAPON_ITEM_VIEW_H
#define WEAPON_ITEM_VIEW_H

#include "base_item_view.h"

class WeaponItemView: public BaseItemView
{
public:
	WeaponItemView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
