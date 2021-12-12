#include "../../inc/saves/gameplay_saver.h"
#include "../../inc/states/state_gameplay.h"

GameplaySaver::GameplaySaver(
	std::shared_ptr<Player> _player,
	std::shared_ptr<Field> _field,
	int _enemies_killed,
	int _steps_count
):	enemies_killed{_enemies_killed},
	steps_count{_steps_count}
{
	this->player = _player->createSaver();
	this->field = _field->createSaver();
	this->offset = "";
}

GameplaySaver::GameplaySaver(std::istringstream& stream)
{
	this->offset = "";
	// parse string
	std::string line = "";
	std::string left_op;
	int parameter;
	while (!stream.eof())
	{
		std::getline(stream, line, '\n');
		if (line[0] == '#') // comment
			continue;
		line.erase(0, line.find_first_not_of(' \t'));
		if (line == "")
			continue;
		std::stringstream block(line);
		std::getline(block, left_op, '=');
		if (left_op == "field")
		{
			this->field = std::make_shared<FieldSaver>(stream);
		}
		else if (left_op == "player")
		{
			this->player = std::make_shared<PlayerSaver>(stream);
		}
		else if (left_op == "enemies_killed")
		{
			block >> parameter;
			this->enemies_killed = parameter;
		} else if (left_op == "steps_count")
		{
			block >> parameter;
			this->steps_count = parameter;
		}
	}
}

std::string GameplaySaver::save() const
{
	std::stringstream buffer;
	buffer << this->offset << "field=" << this->field->save() << std::endl;
	buffer << this->offset << "player=" << this->player->save() << std::endl;
	buffer << this->offset << "enemies_killed=" << this->enemies_killed << std::endl;
	buffer << this->offset << "steps_count=" << this->steps_count << std::endl;
	return buffer.str();
}

std::unique_ptr<StateGameplay> GameplaySaver::load(
	Game& game_object,
	std::shared_ptr<Renderer> _renderer
) const
{
	std::unique_ptr<StateGameplay> state;
	state = std::make_unique<StateGameplay>(
		game_object,
		_renderer,
		this->field->load(),
		this->player->load(),
		this->enemies_killed,
		this->steps_count
	);
	return std::move(state);
}
