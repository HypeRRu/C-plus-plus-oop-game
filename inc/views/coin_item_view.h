#ifndef COIN_ITEM_VIEW_H
#define COIN_ITEM_VIEW_H

#include "base_item_view.h"

class CoinItemView: public BaseItemView
{
public:
	CoinItemView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
