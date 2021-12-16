#ifndef FILE_WRITE_ERROR_H
#define FILE_WRITE_ERROR_H

#include "game_error.h"

class FileWriteError: public GameError
{
public:
	explicit FileWriteError() noexcept;

	std::string what() const;
protected:
};

#endif