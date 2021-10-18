#include "../../inc/views/daemon_enemy_view.h"

DaemonEnemyView::DaemonEnemyView(size_t x, size_t y): BaseEntityView(x, y)
{}

const std::string DaemonEnemyView::getTextureAlias() const
{
	return "enemy_daemon";
}
