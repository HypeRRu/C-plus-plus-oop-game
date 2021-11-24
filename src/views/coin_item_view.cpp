#include "../../inc/views/coin_item_view.h"

CoinItemView::CoinItemView(size_t x, size_t y): BaseItemView(x, y)
{}

const std::string CoinItemView::getTextureAlias() const
{
	return "coin_item";
}
