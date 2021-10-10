#ifndef BASE_OBSERVED_H
#define BASE_OBSERVED_H

#include "../interfaces/observed.h"

class Action;

class BaseObserved: public Observed
{
public:
	void setObserver(std::shared_ptr<GameObserver> observer);
	GameObserver& getObserver() const;
	bool handleAction(Action& action);
protected:
	std::weak_ptr<GameObserver> observer;
};

#endif
