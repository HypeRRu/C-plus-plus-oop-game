#ifndef PARSE_ERROR_H
#define PARSE_ERROR_H

#include "game_error.h"

class ParseError: public GameError
{
public:
	explicit ParseError(
		const std::string& _object_name,
		const std::string& _fields_missing
	) noexcept;

	std::string what() const;
protected:
	std::string object_name;
	std::string missing_list;
};

#endif