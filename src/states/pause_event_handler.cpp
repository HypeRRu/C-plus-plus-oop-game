#include "../../inc/states/pause_event_handler.h"

PauseEventHandler::PauseEventHandler(StatePause& _state):
	state{_state}
{
	this->setNext(nullptr);
}

bool PauseEventHandler::handleEvent(Event e)
{
	switch (e)
	{
		case Event::EventMoveUp:
		case Event::EventMoveLeft:
			this->state.getWindow()->previousButton();
			return true;
		case Event::EventMoveDown:
		case Event::EventMoveRight:
			this->state.getWindow()->nextButton();
			return true;
		case Event::EventConfirmation:
			this->state.getWindow()->clickButton();
			return true;
		case Event::EventGoBack:
			this->state.play();
			return true;
		case Event::EventGameClosed:
			this->state.getGame().exit();
			return true;
		default:
			if (this->next_handler.get())
				return this->next_handler->handleEvent(e);
	}
	return false;
}
