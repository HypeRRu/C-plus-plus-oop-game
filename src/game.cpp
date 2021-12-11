#include "../inc/game.h"

const int cell_size = 60;

Game::Game(): running{false}
{
	GameConfig& config = GameConfig::instance();
	this->renderer = std::make_shared<Renderer>(
		cell_size * config.getFieldSize().first, 
		cell_size * config.getFieldSize().second, 
		"Game"
	);
	if (config.getLogEnabled())
	{
		Logger::instance().setLogAll(
			config.getLogAll()
		);
		Logger::instance().addStream(
			std::make_shared<FileStream>(
				config.getLogFile()
			),
			"filelog"
		);
	}
	this->manager = std::make_shared<WindowManager>(
		this->renderer->getWindow()
	);

	auto state_menu = std::make_unique<StateMenu>(
		*this, this->renderer
	);
	this->newState(std::move(state_menu));
}

bool Game::run()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using sclock = std::chrono::system_clock;

	this->running = true;
	sclock::time_point previous_frame = sclock::now();
	while (this->running)
	{
		sclock::time_point renderStarts = sclock::now();
		this->manager->processEvents();
		if (!this->running)
			break;
		states.back()->update(
			 std::chrono::duration_cast<std::chrono::milliseconds>(
			 	renderStarts - previous_frame
			 ).count()
		);
		this->renderer->renderFrame();

		sleep_until(renderStarts + 45ms); /* fps limiter */
		previous_frame = renderStarts;
	}
	return true;
}

bool Game::exit()
{
	this->running = false;
	GameConfig::instance().save();
	return true;
}

bool Game::newState(std::unique_ptr<BaseState> state)
{
	this->states.push_back(std::move(state));
	this->manager->setEventHandler(
		this->states.back()->getEventHandler()
	);
	this->states.back()->showing();
	return true;
}

bool Game::popState()
{
	this->states.pop_back();
	if (!this->states.size())
	{
		this->exit();
		return false;
	}
	this->manager->setEventHandler(
		this->states.back()->getEventHandler()
	);
	this->states.back()->showing();
	return true;
}
