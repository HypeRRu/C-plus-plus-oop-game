#include "../../inc/views/gargoyle_enemy_view.h"

GargoyleEnemyView::GargoyleEnemyView(size_t x, size_t y): BaseEntityView(x, y)
{}

const std::string GargoyleEnemyView::getTextureAlias() const
{
	return "enemy_gargoyle";
}
