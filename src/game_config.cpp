#include "../inc/game_config.h"

#include <iostream>
GameConfig::GameConfig() /* game configuration by default */
{
	this->loader = std::make_shared<ConfigLoader>();
	this->loader->setPath("assets/config.txt");
	this->loader->load(*this);
}

GameConfig& GameConfig::instance()
{
	static GameConfig config;
	return config;
}

void GameConfig::save()
{
	this->loader->save();
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

void GameConfig::setFieldWidth(int width)
{
	this->field_width = width;
}

void GameConfig::setFieldHeight(int height)
{
	this->field_height = height;
}

void GameConfig::setWallsCount(int count)
{
	this->walls_count = count;
}

void GameConfig::setControls(std::map<sf::Keyboard::Key, Event> controls)
{
	this->controls = controls;
}

void GameConfig::setLogEnabled(bool enabled)
{
	this->log_enabled = enabled;
}

void GameConfig::setLogFile(const std::string& filepath)
{
	this->log_file = filepath;
}

void GameConfig::setLogAll(bool state)
{
	this->log_all = state;
}

void GameConfig::setConsoleLogEnabled(bool state)
{
	this->console_log_enabled = state;
}

