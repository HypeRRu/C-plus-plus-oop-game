#ifndef GAME_LOGIC_ERROR_H
#define GAME_LOGIC_ERROR_H

#include "game_error.h"

class GameLogicError: public GameError
{
public:
	explicit GameLogicError(
		const std::string& _msg
	) noexcept;

	std::string what() const;
protected:
	std::string msg;
};

#endif