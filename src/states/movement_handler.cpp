#include "../../inc/states/movement_handler.h"
#include "../../inc/actions/game_observer.h"

MovementHandler::MovementHandler(std::shared_ptr<Player> _player)
{
	this->player = _player;
}

bool MovementHandler::handleEvent(Event e)
{
	switch (e)
	{
		case Event::EventMoveUp:
		{
			ActionMove act(
				*this->player.get(),
				{
					this->player->getX(),
					this->player->getY() - 1
				},
				false
			);
			return this->player->getObserver().handleAction(act);
		}
		case Event::EventMoveRight:
		{
			ActionMove act(
				*this->player.get(),
				{
					this->player->getX() + 1,
					this->player->getY()
				},
				false
			);
			return this->player->getObserver().handleAction(act);
		}
		case Event::EventMoveDown:
		{
			ActionMove act(
				*this->player.get(),
				{
					this->player->getX(),
					this->player->getY() + 1
				},
				false
			);
			return this->player->getObserver().handleAction(act);
		}
		case Event::EventMoveLeft:
		{
			ActionMove act(
				*this->player.get(),
				{
					this->player->getX() - 1,
					this->player->getY()
				},
				false
			);
			return this->player->getObserver().handleAction(act);
		}
		default:
			if (this->next_handler.get())
				return this->next_handler->handleEvent(e);
	}
	return false;
}
