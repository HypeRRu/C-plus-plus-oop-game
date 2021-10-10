#ifndef OBSERVED_H
#define OBSERVED_H

#include <memory>

class GameObserver;

class Observed
{
public:
	virtual void setObserver(std::shared_ptr<GameObserver> observer) = 0;
	virtual GameObserver& getObserver() const = 0;
};

#endif
