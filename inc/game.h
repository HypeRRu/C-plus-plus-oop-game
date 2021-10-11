#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

#include "utils/field_generator.h"
#include "utils/items_generator.h"
#include "utils/enemies_generator.h"
#include "field.h"

#include "graphics/renderer.h"
#include "game_logic.h"

#include "entities/player.h"
#include "actions/action.h"
#include "actions/action_move.h"
#include "entities/base_enemy.h"
#include "entities/base_entity.h"
#include "entities/regular_enemy.h"
#include "entities/daemon_enemy.h"

#include "actions/game_observer.h"

class GameObserver;
class Field;
class Renderer;

class Game
{
public:
	Game();
	~Game() = default;

	bool run();
	bool fillField();
	bool placeItems();
	bool placeEnemies();

	Renderer& getRenderer() const;
	Field& getField() const;
	Player& getPlayer() const;
	std::map<std::pair<size_t, size_t>, enemy_sptr> getEnemies() const;
	std::shared_ptr<Field> getFieldPtr() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<Player> getPlayerPtr() const;
private:
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<Field> field;
	FieldGenerator generator;
	std::shared_ptr<GameObserver> observer;
	std::shared_ptr<Player> player;
	std::map<std::pair<size_t, size_t>, enemy_sptr> enemies;
};

#endif
