#include "../../inc/saves/field_saver.h"

FieldSaver::FieldSaver(
	size_t _width,
	size_t _height,
	const Field& field_instance
): width{_width}, height{_height}
{
	this->cells.reserve(this->width * this->height);
	for (size_t y = 0; y < this->height; ++y)
	{
		for (size_t x = 0; x < this->width; ++x)
		{
			this->cells.push_back(
				field_instance.getCell(x, y).createSaver()
			);
		}
	}
	this->offset = "";
}

FieldSaver::FieldSaver(std::istringstream& stream):
	width{0}, height{0}
{
	this->offset = "";
	// parse string
	std::string line = "";
	std::string left_op;
	std::string limit = this->offset+"]";
	while (!stream.eof())
	{
		std::getline(stream, line, '\n');
		if (line[0] == '#') // comment
			continue;
		if (line == limit) // end of block
			break;
		line.erase(0, line.find_first_not_of(' \t'));
		if (line == "")
			continue;
		std::stringstream block(line);
		std::getline(block, left_op, '=');
		if (left_op == "field_size")
		{
			std::pair<size_t, size_t> sizes;
			block >> sizes;
			this->width = sizes.first;
			this->height = sizes.second;
		}
		else if (left_op == "cell")
		{
			std::shared_ptr<CellSaver> sv = std::make_shared<CellSaver>(stream);
			if (!sv.get())
				throw GameLogicError{"Unable to create game field!"};
			this->cells.push_back(sv);
		}
	}
	this->checkParams();
}

void FieldSaver::checkParams() const
{
	std::string missing_params = "";
	if (!this->width)
		missing_params += "field_width\n";
	if (!this->height)
		missing_params += "field_height\n";
	if (missing_params == "")
	{
		if (this->cells.size() < this->width * this->height)
			missing_params += "cells x" + std::to_string(
				this->width * this->height - this->cells.size()
			);
	}
	if (missing_params != "")
		throw ParseError{"Field", missing_params};
}	

std::string FieldSaver::save() const
{
	std::stringstream buffer;
	std::string line_offset = this->offset + "\t";
	buffer << "[" << std::endl;
	buffer << line_offset << "field_size=" << std::pair<size_t, size_t>{
		this->width,
		this->height
	} << std::endl;
	for (size_t y = 0; y < this->height; ++y)
	{
		for (size_t x = 0; x < this->width; ++x)
		{
			buffer << line_offset << "cell=" << this->cells[y * this->width + x]->save() << std::endl;
		}
	}
	buffer << this->offset << "]" << std::endl;
	return buffer.str();
}

std::shared_ptr<Field> FieldSaver::load() const
{
	std::shared_ptr<Field> field;
	field = std::make_shared<Field>(
		this->width,
		this->height
	);
	if (!field.get())
		throw GameLogicError{"Unable to create game field!"};
	for (auto& cell: this->cells)
	{
		std::shared_ptr<Cell> cell_object = cell->load();
		if (
			&(field->getCell(
				cell_object->getX(),
				cell_object->getY()
			)) != nullptr
		)
			throw GameLogicError{"Unable to create game field!"};
		field->setCell(
			cell_object->getX(),
			cell_object->getY(),
			cell_object.get()
		);
		if (cell->getType() == "EndCell")
			field->setEnd(
				cell_object->getX(),
				cell_object->getY()
			);
		else if (cell->getType() == "StartCell")
			field->setStart(
				cell_object->getX(),
				cell_object->getY()
			);
	}	
	return field;
}
