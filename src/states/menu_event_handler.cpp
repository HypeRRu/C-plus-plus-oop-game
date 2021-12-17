#include "../../inc/states/menu_event_handler.h"

MenuEventHandler::MenuEventHandler(StateMenu& _state):
	state{_state}
{
	this->setNext(nullptr);
}

bool MenuEventHandler::handleEvent(Event e)
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
		case Event::EventGameClosed:
			this->state.getGame().exit();
			return true;
		default:
			if (this->next_handler.get())
				return this->next_handler->handleEvent(e);
	}
	return false;
}
