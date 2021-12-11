#ifndef STATE_PAUSE_H
#define STATE_PAUSE_H

#include <memory>
#include <functional>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "pause_event_handler.h"
#include "state_gameplay.h"
#include "state_save.h"

#include "graphics/renderer.h"
#include "graphics/base_window.h"
#include "graphics/pause_window.h"

class Game;
class Renderer;
class PauseWindow;
class StateGameplay;

class StatePause: public BaseState
{
public:
	StatePause(
		Game& game,
		std::shared_ptr<Renderer> _renderer,
		StateGameplay& _gameplay
	);
	~StatePause();

	Game& getGame() const;
	StateGameplay& getGameplay() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<BaseWindow> getWindow() const;

	void showing() const;

	bool update(int time_passed = 0);

	void play() const;
	void saveGame() const;
	void toMenu() const;
	void exit() const;
protected:
	std::reference_wrapper<StateGameplay> gameplay;
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<BaseWindow> window;
};

#endif