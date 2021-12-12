#ifndef GAMEPLAY_SAVER_H
#define GAMEPLAY_SAVER_H

#include <string>
#include <memory>
#include <vector>

#include "player_saver.h"
#include "field_saver.h"

class StateGameplay;
class Game;
class Renderer;

class GameplaySaver
{
public:
	GameplaySaver(
		std::shared_ptr<Player> _player,
		std::shared_ptr<Field> _field,
		int _enemies_killed,
		int _steps_count
	);

	GameplaySaver(
		std::istringstream& stream
	);

	~GameplaySaver() = default;

	std::string save() const;
	std::unique_ptr<StateGameplay> load(
		Game& game_object,
		std::shared_ptr<Renderer> _renderer
	) const;
protected:
	std::shared_ptr<PlayerSaver> player;
	std::shared_ptr<FieldSaver> field;

	int enemies_killed;
	int steps_count;

	std::string offset;
};

#endif