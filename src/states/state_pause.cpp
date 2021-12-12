#include "../../inc/states/state_pause.h"

StatePause::StatePause(
	Game& game,
	std::shared_ptr<Renderer> _renderer,
	StateGameplay& _gameplay
):	game_object{std::ref(game)}, 
	renderer{_renderer},
	gameplay{std::ref(_gameplay)}
{
	this->window = std::make_shared<PauseWindow>(*this);
	this->renderer->setWindowRendering(this->window);
	this->setEventHandler(
		std::make_shared<PauseEventHandler>(*this)
	);
}

StatePause::~StatePause()
{
	this->renderer->removeWindowRendering();
}

Game& StatePause::getGame() const
{
	return this->game_object.get();
}

StateGameplay& StatePause::getGameplay() const
{
	return this->gameplay.get();
}

std::shared_ptr<Renderer> StatePause::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<BaseWindow> StatePause::getWindow() const
{
	return this->window;
}

void StatePause::showing() const
{
	this->renderer->setWindowRendering(this->window);
}

bool StatePause::update(int time_passed)
{
	return true;
}

void StatePause::saveGame() const
{
	auto state_save = std::make_unique<StateSave>(
		this->getGame(), 
		this->renderer,
		this->gameplay.get()
	);
	this->getGame().newState(std::move(state_save));
}

void StatePause::loadGame() const
{
	auto state_load = std::make_unique<StateLoad>(
		this->getGame(), 
		this->renderer
	);
	this->getGame().newState(std::move(state_load));
}

void StatePause::play() const
{
	this->getGame().popState();
}

void StatePause::toMenu() const
{
	this->play();
	this->getGame().popState();
}

void StatePause::exit() const
{
	this->getGame().exit();
}