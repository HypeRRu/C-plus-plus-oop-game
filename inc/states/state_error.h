#ifndef STATE_ERROR_H
#define STATE_ERROR_H

#include <memory>
#include <functional>
#include <string>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "error_event_handler.h"

#include "graphics/renderer.h"
#include "graphics/message_window.h"

class Game;
class Renderer;
class MessageWindow;

class StateError: public BaseState
{
public:
	StateError(
		Game& game,
		std::shared_ptr<Renderer> _renderer,
		const std::string& message
	);
	~StateError();

	Game& getGame() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<BaseWindow> getWindow() const;
	std::string getMessage() const;

	void showing() const;

	bool update(int time_passed = 0);
	void back() const;
protected:
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<BaseWindow> window;
};

#endif