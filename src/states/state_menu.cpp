#include "../../inc/states/state_menu.h"

StateMenu::StateMenu(
	Game& game,
	std::shared_ptr<Renderer> _renderer
): game_object{std::ref(game)}, renderer{_renderer}
{
	this->window = std::make_shared<MenuWindow>(*this);
	this->renderer->setWindowRendering(this->window);
	this->setEventHandler(
		std::make_shared<MenuEventHandler>(*this)
	);
}

StateMenu::~StateMenu()
{
	this->renderer->removeWindowRendering();
}

Game& StateMenu::getGame() const
{
	return this->game_object.get();
}

std::shared_ptr<Renderer> StateMenu::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<BaseWindow> StateMenu::getWindow() const
{
	return this->window;
}

void StateMenu::showing() const
{
	this->renderer->setWindowRendering(this->window);
}

bool StateMenu::update(int time_passed)
{
	return true;
}

void StateMenu::start() const
{
	auto state_gameplay = std::make_unique<StateGameplay>(
		this->getGame(), 
		this->renderer
	);
	this->getGame().newState(std::move(state_gameplay));
	this->renderer->removeWindowRendering();
}

void StateMenu::loadGame() const
{
	auto state_load = std::make_unique<StateLoad>(
		this->getGame(), 
		this->renderer
	);
	this->getGame().newState(std::move(state_load));
}

void StateMenu::exit() const
{
	this->getGame().exit();
}
