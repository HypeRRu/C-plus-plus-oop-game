#include "../../inc/utils/field_generator.h"

FieldGenerator::FieldGenerator(size_t width, size_t height, double wall_chance) : 
	width{width}, height{height}, wall_chance{wall_chance}
{
	this->cells.reserve(this->height * this->width);
}

std::vector<cell_sptr> FieldGenerator::generateCells()
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
			if (x == 0 || x == this->width-1 || y == 0 || y == this->height-1)
			{
				_cell_ptr = std::make_shared<Cell>(x, y, true);
				this->cells.insert(
					this->cells.begin() + y * this->width + x,
					_cell_ptr
				);
				continue;
			}
			
			has_wall = false;
			if (x == this->start.first && y == this->start.second)
			{
				_cell_ptr = std::make_shared<StartCell>(x, y);
			} else if (x == this->end.first && y == this->end.second)
			{
				_cell_ptr = std::make_shared<EndCell>(x, y);
			} else
			{
				has_wall = (std::rand() % wall_offset) == 0;
				_cell_ptr = std::make_shared<Cell>(x, y, has_wall);
			}
			this->cells.insert(
				this->cells.begin() + y * this->width + x,
				_cell_ptr
			);
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
		this->start.first = std::rand() % (this->width - 2) + 1;
		this->end.first = std::rand() % (this->width - 2) + 1;
		this->start.second = std::rand() % (this->height - 2) + 1;
		this->end.second = std::rand() % (this->height - 2) + 1;

		if (abs(this->start.first - this->end.first) > 1 && abs(this->start.second - this->end.second) > 1)
			valid_start_end = true;
	}
}

const std::pair<size_t, size_t>& FieldGenerator::getStart() const
{
	return this->start;
}

const std::pair<size_t, size_t>& FieldGenerator::getEnd() const
{
	return this->end;
}
