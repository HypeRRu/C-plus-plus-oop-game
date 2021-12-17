#ifndef STATE_LOAD_H
#define STATE_LOAD_H

#include <memory>
#include <functional>
#include <string>
#include <fstream>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "load_event_handler.h"
#include "state_gameplay.h"

#include "graphics/renderer.h"
#include "graphics/base_window.h"
#include "graphics/load_window.h"
#include "state_error.h"

class Game;
class Renderer;
class LoadWindow;
class StateGameplay;

class StateLoad: public BaseState
{
public:
	StateLoad(
		Game& game,
		std::shared_ptr<Renderer> _renderer
	);
	~StateLoad();

	Game& getGame() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<BaseWindow> getWindow() const;

	void showing() const;

	bool update(int time_passed = 0);

	void loadFromSlot(int slot_number = 1) const;
	void back() const;
protected:
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<BaseWindow> window;
};

#endif