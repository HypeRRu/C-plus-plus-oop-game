#include "../../inc/views/regular_enemy_view.h"

RegularEnemyView::RegularEnemyView(size_t x, size_t y): BaseEntityView(x, y)
{}

const std::string RegularEnemyView::getTextureAlias() const
{
	return "enemy_regular";
}
