#include "../../inc/states/state_error.h"

StateError::StateError(
	Game& game,
	std::shared_ptr<Renderer> _renderer,
	const std::string& message
):	game_object{std::ref(game)}, 
	renderer{_renderer}
{
	this->window = std::make_shared<MessageWindow>(message);
	this->renderer->setWindowRendering(this->window);
	this->setEventHandler(
		std::make_shared<ErrorEventHandler>(*this)
	);
}

StateError::~StateError()
{
	this->renderer->removeWindowRendering();
}

Game& StateError::getGame() const
{
	return this->game_object.get();
}

std::shared_ptr<Renderer> StateError::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<BaseWindow> StateError::getWindow() const
{
	return this->window;
}

void StateError::showing() const
{
	this->renderer->setWindowRendering(this->window);
}

bool StateError::update(int time_passed)
{
	return true;
}

void StateError::back() const
{
	this->getGame().popState();
}

