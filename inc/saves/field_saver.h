#ifndef FIELD_SAVER_H
#define FIELD_SAVER_H

#include <string>
#include <memory>
#include <vector>

#include "../field.h"
#include "cell_saver.h"
#include "../interfaces/saver.h"

class Field;

class FieldSaver
{
public:
	FieldSaver(
		size_t _width,
		size_t _height,
		const Field& field_instance
	);

	FieldSaver(
		std::istringstream& stream
	);

	~FieldSaver() = default;

	std::string save() const;
	std::shared_ptr<Field> load() const;
protected:
	size_t width;
	size_t height;
	std::vector<std::shared_ptr<CellSaver>> cells;

	std::string offset;
};

#endif