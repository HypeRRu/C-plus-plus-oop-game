#include "../inc/game_config.h"

GameConfig::GameConfig() /* game configuration by default */
{
	this->field_width = 20;
	this->field_height = 15;
	this->enemies_count = 5;
	this->items_count = 8;
	this->walls_count = 20;
	this->enemies_walk = 3;

	this->controls = std::map<sf::Keyboard::Key, Event>({
		{sf::Keyboard::Up, Event::EventMoveUp},
		{sf::Keyboard::Right, Event::EventMoveRight},
		{sf::Keyboard::Down, Event::EventMoveDown},
		{sf::Keyboard::Left, Event::EventMoveLeft},
		{sf::Keyboard::Escape, Event::EventGoBack}
	});

	this->log_enabled = true;
	this->log_file = "";
	this->log_all = true;
	this->console_log_enabled = false;
}

GameConfig& GameConfig::instance()
{
	static GameConfig config;
	return config;
}

bool GameConfig::changeConfiguration(const Configuration& configuration)
{
	configuration.exec(*this);
	return true;
}

std::pair<int, int> GameConfig::getFieldSize() const
{
	return {
		this->field_width,
		this->field_height
	};
}

int GameConfig::getEnemiesCount() const
{
	return this->enemies_count;
}

int GameConfig::getItemsCount() const
{
	return this->items_count;
}

int GameConfig::getWallsCount() const
{
	return this->walls_count;
}

int GameConfig::getEnemiesWalk() const
{
	return this->enemies_walk;
}


std::map<sf::Keyboard::Key, Event> GameConfig::getControls() const
{
	return this->controls;
}


bool GameConfig::getLogEnabled() const
{
	return this->log_enabled;
}

std::string GameConfig::getLogFile() const
{
	return this->log_file;
}

bool GameConfig::getLogAll() const
{
	return this->log_all;
}

bool GameConfig::getConsoleLogEnabled() const
{
	return this->console_log_enabled;
}

void GameConfig::setEnemiesCount(int count)
{
	this->enemies_count = count;
}

void GameConfig::setItemsCount(int count)
{
	this->items_count = count;
}

void GameConfig::setEnemiesWalk(int steps)
{
	this->enemies_walk = steps;
}
