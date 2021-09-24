#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "../cells/cell.h"
#include "../cells/end_cell.h"
#include "../cells/start_cell.h"

#include <vector>
#include <cstdlib>
#include <ctime>

using cell_sptr = std::shared_ptr<Cell>;

class FieldGenerator
{
public:
	
	FieldGenerator(size_t width = 0, size_t height = 0, double wall_chance = 0.1);
	~FieldGenerator() = default;

	std::vector<cell_sptr> generateCells();
private:
	std::vector<cell_sptr> cells;

	size_t width;
	size_t height;

	size_t start_x, start_y;
	size_t end_x, end_y;

	double wall_chance;

	void generateStartEnd();
};

#endif