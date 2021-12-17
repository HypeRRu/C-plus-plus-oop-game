#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include <stack>

#include "graphics/renderer.h"
#include "states/base_state.h"
#include "states/state_gameplay.h"
#include "states/state_menu.h"
#include "states/window_manager.h"
#include "logger/file_stream.h"

#include "interfaces/game_rule.h"
#include "interfaces/configuration.h"

class StateGameplay;
class StateMenu;

class Game
{
public:
	Game();
	bool run();
	bool exit();
	bool newState(std::unique_ptr<BaseState> state);
	bool popState();

	bool toMenu();
protected:
	bool running;

	std::shared_ptr<WindowManager> manager;
	std::shared_ptr<Renderer> renderer;
	std::vector<std::unique_ptr<BaseState>> states;
};

#endif