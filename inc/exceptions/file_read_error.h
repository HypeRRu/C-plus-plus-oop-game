#ifndef FILE_READ_ERROR_H
#define FILE_READ_ERROR_H

#include "game_error.h"

class FileReadError: public GameError
{
public:
	explicit FileReadError(
		const std::string& _unexpected = ""
	) noexcept;

	std::string what() const;
protected:
	std::string unexpected;
};

#endif