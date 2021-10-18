#ifndef SHIELD_ITEM_VIEW_H
#define SHIELD_ITEM_VIEW_H

#include "base_item_view.h"

class ShieldItemView: public BaseItemView
{
public:
	ShieldItemView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
