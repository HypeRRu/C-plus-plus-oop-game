#ifndef GAME_ERROR_H
#define GAME_ERROR_H

#include <string>

class GameError
{
public:
	explicit GameError() noexcept;
	explicit GameError(const std::string& _msg) noexcept;
	explicit GameError(const GameError& other) noexcept;

	virtual std::string what() const;
protected:
	std::string msg;
};

#endif