#ifndef STATE_SAVE_H
#define STATE_SAVE_H

#include <memory>
#include <functional>
#include <string>
#include <fstream>

#include "base_state.h"
#include "../game.h"
#include "../game_config.h"
#include "save_event_handler.h"

#include "graphics/renderer.h"
#include "graphics/base_window.h"
#include "graphics/save_window.h"

class Game;
class Renderer;
class SaveWindow;

class StateSave: public BaseState
{
public:
	StateSave(
		Game& game,
		std::shared_ptr<Renderer> _renderer,
		StateGameplay& _gameplay
	);
	~StateSave();

	Game& getGame() const;
	StateGameplay& getGameplay() const;
	std::shared_ptr<Renderer> getRendererPtr() const;
	std::shared_ptr<BaseWindow> getWindow() const;

	void showing() const;

	bool update(int time_passed = 0);

	void saveInSlot(int slot_number = 1) const;
	void back() const;
protected:
	std::reference_wrapper<StateGameplay> gameplay;
	std::reference_wrapper<Game> game_object;
	std::shared_ptr<Renderer> renderer;
	std::shared_ptr<BaseWindow> window;
};

#endif