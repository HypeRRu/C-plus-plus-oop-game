#ifndef REGULAR_ENEMY_VIEW_H
#define REGULAR_ENEMY_VIEW_H

#include "base_entity_view.h"

class RegularEnemyView: public BaseEntityView
{
public:
	RegularEnemyView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
