#ifndef SAVER_H
#define SAVER_H

#include "../logger/operators.h"
#include "../exceptions/game_error.h"
#include "../exceptions/file_read_error.h"
#include "../exceptions/game_logic_error.h"
#include "../exceptions/parse_error.h"

class Saver
{
public:
	virtual std::string save() const = 0;
	virtual void checkParams() const = 0;
};

#endif