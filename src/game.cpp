#include "../inc/game.h"

const int width = 20;
const int height = 15;
const int cell_size = 60;

Game::Game() : generator{width, height}
{
	this->field = std::make_shared<Field>(width, height);
	this->renderer = std::make_shared<Renderer>(
		cell_size * width, cell_size * height, "Game"
	);
	this->fillField();
	this->player = std::make_shared<Player>(
		this->field->getStart().first,
		this->field->getStart().second
	);
	this->observer = std::make_shared<GameObserver>(*this);

	this->field->setObserver(this->observer);
	this->renderer->setObserver(this->observer);
	this->player->setObserver(this->observer);
	this->field->onCellsAdded();

	this->placeItems();
	this->placeEnemies();

	this->player->spawn();
}

bool Game::run()
{
	using namespace std::this_thread;
	using namespace std::chrono_literals;
	using std::chrono::system_clock;

	GameLogic event_processor;
	std::pair<size_t, size_t> pl_movement;

    bool running = true;
    std::chrono::system_clock::time_point updated = std::chrono::system_clock::now();

	std::cout << "Running" << std::endl;
	while (running)
	{
		std::chrono::system_clock::time_point renderStarts = std::chrono::system_clock::now();
		pl_movement = event_processor.processWindowEventsAndGetMovement(
			this->renderer->getWindow()
		);
		if (pl_movement != std::pair<size_t, size_t>{0, 0})
		{
			ActionMove act(
				this->getPlayer(),
				std::pair<size_t, size_t>{
					this->player->getX() + pl_movement.first,
					this->player->getY() + pl_movement.second
				},
				false
			);
			this->player->handleAction(act);
		}
		if (std::chrono::system_clock::now() - updated >= 1.5s)
		{
			updated = std::chrono::system_clock::now();
			for (auto enemy: this->getEnemies())
			{			
					enemy.second->update();
			}
		}
		running = this->getRenderer().renderFrame();
		sleep_until(renderStarts + .045s); /* fps limiter */
	}
	return true;
}

bool Game::fillField()
{
	std::vector<std::shared_ptr<Cell>> generated_cells = this->generator.generateCells();
	this->field->setStart(this->generator.getStart());
	this->field->setEnd(this->generator.getEnd());

	for (size_t y = 0; y < this->field->getHeight(); y++)
	{
		for (size_t x = 0; x < this->field->getWidth(); x++)
		{
			this->field->setCell(
				x, 
				y, 
				generated_cells.at(y * this->field->getWidth() + x).get()
			);
		}
	}
	return true;
}

bool Game::placeItems()
{
	ItemsGenerator item_generator(this->getField());
	auto items = item_generator.generateItems();
	for (auto _item: items)
	{
		_item.second->setObserver(this->observer);
		this->field->getCell(
			_item.first.first,
			_item.first.second
		).setItem(_item.second);
	}
	return true;
}

bool Game::placeEnemies()
{
	EnemiesGenerator enemies_generator(this->getField());
	this->enemies = std::make_shared<enemies_map>(enemies_generator.generateEnemies());
	this->observer->setEnemies(this->enemies);
	for (auto enemy: this->getEnemies())
	{
		enemy.second->setObserver(this->observer);
		enemy.second->spawn();
	}
	return true;
}

Renderer& Game::getRenderer() const
{
	return *this->renderer.get();
}

Field& Game::getField() const
{
	return *this->field.get();
}

Player& Game::getPlayer() const
{
	return *this->player.get();
}

std::map<std::pair<size_t, size_t>, enemy_sptr> Game::getEnemies() const
{
	return *this->enemies.get();
}

std::shared_ptr<Field> Game::getFieldPtr() const
{
	return this->field;
}

std::shared_ptr<Renderer> Game::getRendererPtr() const
{
	return this->renderer;
}

std::shared_ptr<Player> Game::getPlayerPtr() const
{
	return this->player;
}
