#include "../../inc/actions/base_observed.h"
#include "../../inc/actions/game_observer.h"

void BaseObserved::setObserver(std::shared_ptr<GameObserver> observer)
{
	this->observer = observer;
	this->getObserver();
}

GameObserver& BaseObserved::getObserver() const
{
	return *this->observer.lock().get();
}

bool BaseObserved::handleAction(Action& action)
{
	return this->getObserver().handleAction(action);	
}
