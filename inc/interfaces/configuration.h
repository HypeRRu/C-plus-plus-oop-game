#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class GameConfig;

class Configuration
{
public:
	virtual bool exec(GameConfig& config) const = 0;
};

#endif