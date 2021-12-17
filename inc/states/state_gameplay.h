#ifndef STATE_GAMEPLAY_H
#define STATE_GAMEPLAY_H

#include <memory>
#include <functional>
#include <set>
#include <cmath>
#include <sstream>
#include <string>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "gameplay_event_handler.h"
#include "state_pause.h"

#include "../interfaces/game_rule.h"
#include "../interfaces/ichecker.h"
#include "../configurations/rule_checker.h"
#include "../configurations/enemies_to_kill_rule.h"
#include "../configurations/max_steps_rule.h"
#include "../configurations/money_rule.h"
#include "../configurations/enemies_count_configuration.h"
#include "../configurations/items_count_configuration.h"
#include "../configurations/enemies_walk_configuration.h"

#include "utils/field_generator.h"
#include "utils/items_generator.h"
#include "utils/enemies_generator.h"

#include "field.h"
#include "cells/cell.h"
#include "graphics/renderer.h"
#include "actions/game_observer.h"

#include "entities/player.h"
#include "entities/base_enemy.h"


class Field;
class GameObserver;
class Renderer;
class Game;
class GameRule;
class StatePause;
class GameplaySaver;

class StateGameplay: public BaseState
{
public:
	StateGameplay(
		Game& game,
		std::shared_ptr<Renderer> _renderer
	);

	StateGameplay(
		Game& game,
		std::shared_ptr<Renderer> _renderer,
		std::shared_ptr<Field> _field,
		std::shared_ptr<Player> _player,
		int _enemies_killed,
		int _steps_count
	); // load game

	~StateGameplay();

	void showing() const;
	void initDraw() const;
	void initRules();

	bool update(int time_passed = 0);
	bool pause(bool pause_state = true);
	bool generateLevel();
	std::string getSave() const;

	bool isCompleted();
	bool isPaused() const;
	Game& getGame() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<Field> getFieldPtr() const;
	std::shared_ptr<Player> getPlayerPtr() const;

	int getEnemiesKilled() const;
	int getStepsCount() const;
	void increaseEnemiesKilled();
	void increaseStepsCount();

	std::shared_ptr<GameplaySaver> createSaver() const;
protected:
	void configureObserver();

	bool is_paused;
	bool is_running;
	int time_to_update; /* in milliseconds */ 
	int steps_to_update;

	std::shared_ptr<IChecker> checker;
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Field> field;
	std::shared_ptr<GameObserver> observer;
	std::shared_ptr<Player> player;

	int enemies_killed;
	int steps_count;
};

#endif