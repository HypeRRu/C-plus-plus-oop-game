#ifndef STATE_MENU_H
#define STATE_MENU_H

#include <memory>
#include <functional>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "menu_event_handler.h"
#include "state_gameplay.h"

#include "graphics/renderer.h"
#include "graphics/base_window.h"
#include "graphics/menu_window.h"

class Game;
class Renderer;
class MenuWindow;
class StateGameplay;

class StateMenu: public BaseState
{
public:
	StateMenu(
		Game& game,
		std::shared_ptr<Renderer> _renderer
	);
	~StateMenu();

	Game& getGame() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<BaseWindow> getWindow() const;

	void showing() const;

	bool update(int time_passed = 0);

	void start() const;
	void exit() const;
protected:
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<BaseWindow> window;
};

#endif