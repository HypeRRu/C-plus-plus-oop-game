#include "../../inc/actions/base_observed.h"
#include "../../inc/actions/game_observer.h"

void BaseObserved::setObserver(std::shared_ptr<GameObserver> observer)
{
	this->observer = observer;
}

GameObserver& BaseObserved::getObserver() const
{
	return *this->observer.lock().get();
}
