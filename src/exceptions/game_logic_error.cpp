#include "../../inc/exceptions/game_logic_error.h"

GameLogicError::GameLogicError(const std::string& _msg) noexcept: 
	msg{_msg}
{}

std::string GameLogicError::what() const
{
	std::string message = "Game Logic Error: \n";
	message = message + this->msg;
	return message;
}
