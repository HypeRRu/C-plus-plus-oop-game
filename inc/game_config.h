#ifndef GAME_CONFIG_H
#define GAME_CONFIG_H

#include <string>
#include <map>
#include <memory>

#include "interfaces/configuration.h"
#include <SFML/Graphics.hpp>
#include "configurations/config_loader.h"

enum class Event
{
	EventMoveUp,
	EventMoveRight,
	EventMoveDown,
	EventMoveLeft,
	EventGoBack,
	EventGameClosed,
	EventConfirmation
};

class ConfigLoader;

class GameConfig
{
public:
	static GameConfig& instance();
	void save();

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

	void setFieldWidth(int width);
	void setFieldHeight(int height);
	void setWallsCount(int count);
	void setControls(std::map<sf::Keyboard::Key, Event> controls);
	void setLogEnabled(bool enabled);
	void setLogFile(const std::string& filepath);
	void setLogAll(bool state);
	void setConsoleLogEnabled(bool state);

	void setEnemiesCount(int count);
	void setItemsCount(int count);
	void setEnemiesWalk(int steps);
protected:
	GameConfig();

	std::shared_ptr<ConfigLoader> loader;
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