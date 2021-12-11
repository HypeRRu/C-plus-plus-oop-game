#include "../../inc/states/state_save.h"

StateSave::StateSave(
	Game& game,
	std::shared_ptr<Renderer> _renderer,
	StateGameplay& _gameplay
):	game_object{std::ref(game)}, 
	renderer{_renderer},
	gameplay{std::ref(_gameplay)}
{
	this->window = std::make_shared<SaveWindow>(*this);
	this->renderer->setWindowRendering(this->window);
	this->setEventHandler(
		std::make_shared<SaveEventHandler>(*this)
	);
}

StateSave::~StateSave()
{
	this->renderer->removeWindowRendering();
}

Game& StateSave::getGame() const
{
	return this->game_object.get();
}

StateGameplay& StateSave::getGameplay() const
{
	return this->gameplay.get();
}

std::shared_ptr<Renderer> StateSave::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<BaseWindow> StateSave::getWindow() const
{
	return this->window;
}

void StateSave::showing() const
{
	this->renderer->setWindowRendering(this->window);
}

bool StateSave::update(int time_passed)
{
	return true;
}

void StateSave::saveInSlot(int slot_number) const
{
	// save into file
	std::string fname = "assets/saves/slot";
	fname = fname + std::to_string(slot_number) + ".txt";
	std::string save_content; // save content will be here
	save_content = this->getGameplay().getSave();
	std::fstream file;
	file.open(fname, std::fstream::out);
	if (file.is_open())
		file << save_content;
	file.close();
	this->back();
}

void StateSave::back() const
{
	this->getGame().popState();
}

