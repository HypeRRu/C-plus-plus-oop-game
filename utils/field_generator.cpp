#include "field_generator.h"

FieldGenerator::FieldGenerator(size_t width, size_t height, double wall_chance) : 
	width{width}, height{height}, wall_chance{wall_chance}
{}

std::vector<cell_ptr> FieldGenerator::generateCells()
{
	std::srand(std::time(NULL));
	bool has_wall;
	int wall_offset = (int) (1 / this->wall_chance);
	this->generateStartEnd();
	std::shared_ptr<Cell> _cell_ptr;

	for (size_t y = 0; y < this->height; y++)
	{
		for (size_t x = 0; x < this->width; x++)
		{
			has_wall = false;
			if (x == this->start_x && y == this->start_y)
			{
				_cell_ptr = std::make_shared<StartCell>(x, y);
			} else if (x == this->end_x && y == this->end_y)
			{
				_cell_ptr = std::make_shared<EndCell>(x, y);
			} else
			{
				has_wall = (std::rand() % wall_offset) == 0;
				_cell_ptr = std::make_shared<Cell>(x, y, has_wall);
			}
			this->cells.push_back(_cell_ptr);
		}
	}

	return this->cells;
}

void FieldGenerator::generateStartEnd()
{
	std::srand(std::time(NULL));
	bool valid_start_end = false;

	if (this->width <=2 && this->height <= 2)
		return; // mb throw error

	while (!valid_start_end)
	{
		this->start_x = std::rand() % this->width;
		this->end_x = std::rand() % this->width;
		this->start_y = std::rand() % this->height;
		this->end_y = std::rand() % this->height;

		if (abs(this->start_x - this->end_x) > 1 && abs(this->start_y - this->end_y) > 1)
			valid_start_end = true;
	}
}