#ifndef MOVEMENT_HANDLER_H
#define MOVEMENT_HANDLER_H

#include <memory>

#include "base_event_handler.h"
#include "../entities/player.h"
#include "../actions/action_move.h"

class MovementHandler: public BaseEventHandler
{
public:
	MovementHandler(std::shared_ptr<Player> _player);
	bool handleEvent(Event e);
protected:
	std::shared_ptr<Player> player;
};

#endif