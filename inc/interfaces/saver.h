#ifndef SAVER_H
#define SAVER_H

#include <string>
#include <memory>
#include <sstream>

#include "../actions/base_observed.h"
#include "../logger/operators.h"

class Saver
{
public:
	virtual std::string save() const = 0;
	virtual std::shared_ptr<BaseObserved> load() const = 0;
};

#endif