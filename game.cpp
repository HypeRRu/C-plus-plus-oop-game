#include "game.h"

const int width = 20;
const int height = 15;
const int cell_size = 60;

Game::Game()
{
	this->field = std::make_unique<Field>(Field(width, height));
	this->renderer = std::make_unique<Renderer>(
		Renderer(cell_size * width, cell_size * height, "Game")
	);
	this->generator = FieldGenerator(width, height);
	this->fillField();
}

bool Game::run()
{
	using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;

    bool running = true;

	std::cout << "Running" << std::endl;
	while (running)
	{
		std::chrono::system_clock::time_point renderStarts = std::chrono::system_clock::now();
		running = this->getRenderer().renderFrame();
		sleep_until(renderStarts + .2s);
	}
	return true;
}

bool Game::fillField()
{
	std::vector<std::shared_ptr<Cell>> generated_cells = this->generator.generateCells();
	for (size_t y = 0; y < this->field->getHeight(); y++)
	{
		for (size_t x = 0; x < this->field->getWidth(); x++)
		{
			this->field->setCell(
				x, 
				y, 
				generated_cells.at(y * this->field->getWidth() + x).get()
			);
			this->getRenderer().addObject(
				x, y,
				cell_size, cell_size,
				generated_cells.at(
					y * this->field->getWidth() + x
				).get()->getTextureAlias(),
				true
			);
		}
	}
	return true;
}

Renderer& Game::getRenderer() const
{
	return *this->renderer.get();
}