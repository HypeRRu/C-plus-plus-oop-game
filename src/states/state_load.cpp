#include "../../inc/states/state_load.h"
#include "../../inc/saves/gameplay_saver.h"

StateLoad::StateLoad(
	Game& game,
	std::shared_ptr<Renderer> _renderer
):	game_object{std::ref(game)}, 
	renderer{_renderer}
{
	this->window = std::make_shared<LoadWindow>(*this);
	this->renderer->setWindowRendering(this->window);
	this->setEventHandler(
		std::make_shared<LoadEventHandler>(*this)
	);
}

StateLoad::~StateLoad()
{
	this->renderer->removeWindowRendering();
}

Game& StateLoad::getGame() const
{
	return this->game_object.get();
}

std::shared_ptr<Renderer> StateLoad::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<BaseWindow> StateLoad::getWindow() const
{
	return this->window;
}

void StateLoad::showing() const
{
	this->renderer->setWindowRendering(this->window);
}

bool StateLoad::update(int time_passed)
{
	return true;
}

void StateLoad::loadFromSlot(
	int slot_number
) const
{
	// load from file
	try
	{
		std::string fname = "assets/saves/slot";
		fname = fname + std::to_string(slot_number) + ".txt";
		std::unique_ptr<StateGameplay> state;
		std::string save_content;
		std::fstream file;
		file.open(fname, std::fstream::in);
		if (file.is_open())
			save_content.assign(
				std::istreambuf_iterator<char>(file),
				std::istreambuf_iterator<char>()
			);
		else
			throw FileReadError{};
		file.close();
		std::shared_ptr<GameplaySaver> saver;
		std::istringstream stream(save_content);
		saver = std::make_shared<GameplaySaver>(stream);
		state = saver->load(
			this->getGame(),
			this->getRendererPtr()
		);
		this->getGame().toMenu();
		this->getGame().newState(std::move(state));
	} catch (const GameError& error)
	{
		auto state_error = std::make_unique<StateError>(
			this->getGame(), 
			this->renderer,
			error.what()
		);
		this->getGame().newState(std::move(state_error));
		// std::cout << error.what() << std::endl;
	}
}

void StateLoad::back() const
{
	this->getGame().popState();
}

