#ifndef HEAL_ITEM_VIEW_H
#define HEAL_ITEM_VIEW_H

#include "base_item_view.h"

class HealItemView: public BaseItemView
{
public:
	HealItemView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
