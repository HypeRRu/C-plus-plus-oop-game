#include "../../inc/configurations/config_loader.h"

ConfigLoader::ConfigLoader()
{
	this->config_setters = {
		{"field_width", [](GameConfig& config, const std::string& value = "20")->void{
			config.setFieldWidth(std::stoi(value));
		}},
		{"field_height", [](GameConfig& config, const std::string& value = "15")->void{
			config.setFieldHeight(std::stoi(value));
		}},
		{"enemies_count", [](GameConfig& config, const std::string& value = "5")->void{
			config.setEnemiesCount(std::stoi(value));
		}},
		{"items_count", [](GameConfig& config, const std::string& value = "10")->void{
			config.setItemsCount(std::stoi(value));
		}},
		{"walls_count", [](GameConfig& config, const std::string& value = "20")->void{
			config.setWallsCount(std::stoi(value));
		}},
		{"enemies_walk", [](GameConfig& config, const std::string& value = "3")->void{
			config.setEnemiesWalk(std::stoi(value));
		}},
		{"log_enabled", [](GameConfig& config, const std::string& value = "1")->void{
			config.setLogEnabled(std::stoi(value));
		}},
		{"log_file", [](GameConfig& config, const std::string& value = "")->void{
			config.setLogFile(value);
		}},
		{"log_all", [](GameConfig& config, const std::string& value = "1")->void{
			config.setLogAll(std::stoi(value));
		}},
		{"console_log_enabled", [](GameConfig& config, const std::string& value = "0")->void{
			config.setConsoleLogEnabled(std::stoi(value));
		}}
	};
	this->config_getters = {
		{"field_width", [](GameConfig& config)->std::string{
			return std::to_string(config.getFieldSize().first);
		}},
		{"field_height", [](GameConfig& config)->std::string{
			return std::to_string(config.getFieldSize().second);
		}},
		{"enemies_count", [](GameConfig& config)->std::string{
			return std::to_string(config.getEnemiesCount());
		}},
		{"items_count", [](GameConfig& config)->std::string{
			return std::to_string(config.getItemsCount());
		}},
		{"walls_count", [](GameConfig& config)->std::string{
			return std::to_string(config.getWallsCount());
		}},
		{"enemies_walk", [](GameConfig& config)->std::string{
			return std::to_string(config.getEnemiesWalk());
		}},
		{"log_enabled", [](GameConfig& config)->std::string{
			return std::to_string(config.getLogEnabled());
		}},
		{"log_file", [](GameConfig& config)->std::string{
			return config.getLogFile();
		}},
		{"log_all", [](GameConfig& config)->std::string{
			return std::to_string(config.getLogAll());
		}},
		{"console_log_enabled", [](GameConfig& config)->std::string{
			return std::to_string(config.getConsoleLogEnabled());
		}}
	};
	this->events_map = {
		{"event_up", Event::EventMoveUp},
		{"event_down", Event::EventMoveDown},
		{"event_left", Event::EventMoveLeft},
		{"event_right", Event::EventMoveRight},
		{"event_back", Event::EventGoBack},
		{"event_confirm", Event::EventConfirmation}
	};
}

void ConfigLoader::setPath(const std::string& _path)
{
	this->path = _path;
}

bool ConfigLoader::load(GameConfig& config)
{
	this->settingsByDefault(config);
	std::ifstream file;
	file.open(this->path);
	if (!file.is_open())
		return false;
	this->processFile(file, config);
	file.close();
	return true;
}

void ConfigLoader::save()
{
	std::ofstream file;
	file.open(this->path);
	if (!file.is_open())
		return;
	file << this->prepareToSave();
	file.close();
}

void ConfigLoader::settingsByDefault(GameConfig& config)
{
	for (auto& [key, setter]: this->config_getters)
		setter(config); // set default value
	config.setControls({
		{sf::Keyboard::Up, Event::EventMoveUp},
		{sf::Keyboard::Right, Event::EventMoveRight},
		{sf::Keyboard::Down, Event::EventMoveDown},
		{sf::Keyboard::Left, Event::EventMoveLeft},
		{sf::Keyboard::Escape, Event::EventGoBack},
		{sf::Keyboard::Enter, Event::EventConfirmation}
	});
}

void ConfigLoader::processFile(std::ifstream& file, GameConfig& config)
{
	std::string prev = "";
	std::stringstream block;
	std::string line;
	char first_sym;
	while (!file.eof())
	{
		std::getline(file, line, '\n');
		if (line == prev) continue;
		prev = line;
		if (line[0] == '#')
			continue;
		// catch invalid value errors
		if (!this->processDefaultParam(line, config))
		{
			std::getline(file, line, ']');
			this->processKeyboardParam(line, config);
		}
	}
}

bool ConfigLoader::processDefaultParam(std::string block, GameConfig& config)
{
	std::istringstream stream(block);
	std::string left_op, binding;

	std::getline(stream, left_op, '=');

	if (left_op == "controls")
		return false;
	stream >> binding;
	if (this->config_setters.find(left_op) != this->config_setters.end())
		this->config_setters[left_op](config, binding);

	return true;
}

void ConfigLoader::processKeyboardParam(std::string block, GameConfig& config)
{
	std::istringstream stream(block);
	std::istringstream line;
	std::string left_op;
	int binding;
	sf::Keyboard::Key key;
	std::map<sf::Keyboard::Key, Event> bindings = {
		{sf::Keyboard::Up, Event::EventMoveUp},
		{sf::Keyboard::Right, Event::EventMoveRight},
		{sf::Keyboard::Down, Event::EventMoveDown},
		{sf::Keyboard::Left, Event::EventMoveLeft},
		{sf::Keyboard::Escape, Event::EventGoBack},
		{sf::Keyboard::Enter, Event::EventConfirmation}
	};

	while (!stream.eof())
	{
		std::getline(stream, block, '\n');
		line.str(block);
		if (block[0] == '#')
			continue;
		std::getline(line, left_op, '=');
		line >> binding;
		key = static_cast<sf::Keyboard::Key>(binding);
		if (this->events_map.find(left_op) != this->events_map.end())
		{
			for (auto& [bind, ev]: bindings)
			{
				if (ev == this->events_map[left_op])
				{
					bindings.erase(bind);
					break;
				}
			}
			bindings.insert_or_assign(key, this->events_map[left_op]);
		}
	}
	config.setControls(bindings);
}

std::string ConfigLoader::prepareToSave()
{
	std::stringstream data_to_write;
	GameConfig& config = GameConfig::instance();
	for (auto& [key, getter]: this->config_getters)
		data_to_write << key << "=" << getter(config) << std::endl;
	data_to_write << "controls=[" << std::endl;
	data_to_write << this->prepareKeyBindings();
	data_to_write << "]" << std::endl;
	return data_to_write.str();
}

std::string ConfigLoader::prepareKeyBindings()
{
	std::stringstream controls;
	GameConfig& config = GameConfig::instance();
	for (auto& [key, event]: config.getControls())
	{
		for (auto& [type, ev]: this->events_map)
		{
			if (ev != event)
				continue;
			controls << type << "=" << key << std::endl;
			break;
		}
	}
	return controls.str();
}
