#ifndef FIELD_GENERATOR_H
#define FIELD_GENERATOR_H

#include "../cells/cell.h"
#include "../cells/end_cell.h"
#include "../cells/start_cell.h"

#include "../items/base_item.h"
#include "../items/heal_item.h"

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

	const std::pair<size_t, size_t>& getStart() const;
	const std::pair<size_t, size_t>& getEnd() const;
private:
	std::vector<cell_sptr> cells;

	size_t width;
	size_t height;

	std::pair<size_t, size_t> start;
	std::pair<size_t, size_t> end;

	double wall_chance;

	void generateStartEnd();
};

#endif
