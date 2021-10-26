#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H

#include <memory>
#include <iostream>
#include "../game.h"
#include "action.h"
#include "action_attack.h"
#include "action_move.h"
#include "action_pick_item.h"
#include "action_delete_item.h"
#include "action_delete_enemy.h"
#include "action_add_drawable.h"
#include "action_player_reach_end.h"
#include "../logger/logger.h"

#include "../interfaces/imanager.h"

class Game;

class GameObserver: public IManager
{
public:
	GameObserver(const Game& game_object);
	~GameObserver();

	bool handleAction(ActionMove& action);
	bool handleAction(ActionAttack& action);
	bool handleAction(ActionPickItem& action);
	bool handleAction(ActionDeleteItem& action);
	bool handleAction(ActionDeleteEnemy& action);
	bool handleAction(ActionAddDrawable& action);
	bool handleAction(ActionPlayerReachEnd& action);
protected:
	bool moveLogicForPlayer(ActionMove& action);
	bool moveLogicForEnemy(ActionMove& action);
	
	std::shared_ptr<Field> field;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Player> player;
};

#endif
