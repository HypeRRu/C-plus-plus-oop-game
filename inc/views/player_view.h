#ifndef PLAYER_VIEW_H
#define PLAYER_VIEW_H

#include "base_entity_view.h"

class PlayerView: public BaseEntityView
{
public:
	PlayerView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
