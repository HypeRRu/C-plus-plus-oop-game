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

class Game;

class GameObserver
{
public:
	GameObserver(const Game& game_object);
	~GameObserver();

	void setEnemies(std::shared_ptr<std::map<std::pair<size_t, size_t>, enemy_sptr>> enemies);
	std::map<std::pair<size_t, size_t>, enemy_sptr>& getEnemies();
	bool handleAction(Action& action);

	bool handleActionMove(Action& _action);
	bool handleActionAttack(Action& _action);
	bool handleActionDeleteItem(Action& _action);
	bool handleActionDeleteEnemy(Action& _action);
	bool handleActionPickItem(Action& _action);
	bool handleActionAddDrawable(Action& _action);
	bool handleActionPlayerReachEnd(Action& _action);
protected:
	bool moveLogicForPlayer(ActionMove& action);
	bool moveLogicForEnemy(ActionMove& action);
	
	std::shared_ptr<Field> field;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Player> player;
	std::weak_ptr<std::map<std::pair<size_t, size_t>, enemy_sptr>> enemies;
};

#endif
