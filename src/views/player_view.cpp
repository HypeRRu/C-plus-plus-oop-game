#include "../../inc/views/player_view.h"

PlayerView::PlayerView(size_t x, size_t y): BaseEntityView(x, y)
{}

const std::string PlayerView::getTextureAlias() const
{
	return "player";
}
