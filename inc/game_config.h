#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <string>
#include <map>

#include "interfaces/configuration.h"
#include <SFML/Graphics.hpp>

enum class Event
{
	EventMoveUp,
	EventMoveRight,
	EventMoveDown,
	EventMoveLeft,
	EventGoBack,
	EventGameClosed
};

class GameConfig
{
public:
	static GameConfig& instance();

	GameConfig(const GameConfig&) = delete;
	GameConfig& operator =(const GameConfig&) = delete;

	bool changeConfiguration(const Configuration& configuration);

	std::pair<int, int> getFieldSize() const;
	int getEnemiesCount() const;
	int getItemsCount() const;
	int getWallsCount() const;
	int getEnemiesWalk() const;

	std::map<sf::Keyboard::Key, Event> getControls() const;

	bool getLogEnabled() const;
	std::string getLogFile() const;
	bool getLogAll() const;
	bool getConsoleLogEnabled() const;

	void setEnemiesCount(int count);
	void setItemsCount(int count);
	void setEnemiesWalk(int steps);
protected:
	GameConfig();
	/* rules */
	int field_width;
	int field_height;
	int enemies_count;
	int items_count;
	int walls_count;
	int enemies_walk;
	/* controls */
	std::map<sf::Keyboard::Key, Event> controls;
	/* logs */
	bool log_enabled;
	std::string log_file;
	bool log_all;
	bool console_log_enabled;
};

#endif