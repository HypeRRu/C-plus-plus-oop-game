#include "../../inc/exceptions/game_error.h"

GameError::GameError() noexcept:
	msg{""}
{}

GameError::GameError(const std::string& _msg) noexcept: 
	msg{_msg}
{}

GameError::GameError(const GameError& other) noexcept:
	msg{other.what()}
{}

std::string GameError::what() const
{
	return this->msg;
}
