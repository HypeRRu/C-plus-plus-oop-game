#ifndef GARGOYLE_ENEMY_VIEW_H
#define GARGOYLE_ENEMY_VIEW_H

#include "base_entity_view.h"

class GargoyleEnemyView: public BaseEntityView
{
public:
	GargoyleEnemyView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
