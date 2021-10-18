#ifndef DAEMON_ENEMY_VIEW_H
#define DAEMON_ENEMY_VIEW_H

#include "base_entity_view.h"

class DaemonEnemyView: public BaseEntityView
{
public:
	DaemonEnemyView(size_t x = 0, size_t y = 0);
	const std::string getTextureAlias() const;
};

#endif
