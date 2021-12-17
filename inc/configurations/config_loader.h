#ifndef CONFIG_LOADER_H
#define CONFIG_LOADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <functional>

#include "../game_config.h"

class GameConfig;
enum class Event;

class ConfigLoader
{
public:
	ConfigLoader();
	void setPath(const std::string& _path);
	bool load(GameConfig& config);
	void save();
	void settingsByDefault(GameConfig& config);
protected:
	void processFile(std::ifstream& file, GameConfig& config);
	std::string prepareToSave();
	std::string prepareKeyBindings();

	bool processDefaultParam(std::string block, GameConfig& config);
	void processKeyboardParam(std::string block, GameConfig& config);

	std::string path;

	std::map<
		std::string, 
		std::function<void(GameConfig&, const std::string&)>
	> config_setters;
	std::map<
		std::string,
		std::function<std::string(GameConfig&)>
	> config_getters;
	std::map<
		std::string,
		Event
	> events_map;
};

#endif