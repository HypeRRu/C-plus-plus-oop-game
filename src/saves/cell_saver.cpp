#include "../../inc/saves/cell_saver.h"

CellSaver::CellSaver(
	std::pair<size_t, size_t> _position,
	bool _wall,
	std::weak_ptr<BaseEnemy> _enemy,
	std::weak_ptr<BaseItem> _item,
	const std::string& _cell_type
): position{_position}, wall{_wall}, cell_type{_cell_type}
{
	if (_enemy.lock().get())
	{
		this->enemy = _enemy.lock()->createSaver();
	}
	if (_item.lock().get())
	{
		this->item = _item.lock()->createSaver();
	}
	this->offset = "\t";
}

CellSaver::CellSaver(std::istringstream& stream)
{
	this->offset = "\t";
	// parse string
	std::string line = "";
	std::string left_op;
	int parameter_int;
	std::pair<size_t, size_t> parameter_pair;
	std::string parameter_str;
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
		if (left_op == "type")
		{
			block >> parameter_str;
			this->cell_type = parameter_str;
		}
		else if (left_op == "position")
		{
			block >> parameter_pair;
			this->position = parameter_pair;
		}
		else if (left_op == "wall")
		{
			block >> parameter_int;
			this->wall = parameter_int;
		} else if (left_op == "entity")
		{
			this->enemy = std::make_shared<EnemySaver>(stream);
		} else if (left_op == "item")
		{
			this->item = std::make_shared<ItemSaver>(stream);
		}
	}
}

std::string CellSaver::save() const
{
	std::string line_offset = this->offset+"\t";
	std::stringstream buffer;
	buffer << "[" << std::endl;
	buffer << line_offset << "type=" << this->cell_type << std::endl;
	buffer << line_offset << "position=" << this->position << std::endl;
	buffer << line_offset << "wall=" << this->wall << std::endl;
	if (this->enemy.get())
	{
		buffer << line_offset << "entity=" << 
			this->enemy->save() << std::endl;
	}
	if (this->item.get())
	{
		buffer << line_offset << "item=" << 
			this->item->save() << std::endl;
	}
	buffer << this->offset << "]";
	return buffer.str();
}

std::shared_ptr<Cell> CellSaver::load() const
{
	std::shared_ptr<Cell> cell;
	if (this->cell_type == "Cell")
	{
		cell = std::make_shared<Cell>(
			this->position.first,
			this->position.second,
			this->wall
		);
	} else if (this->cell_type == "EndCell")
	{
		cell = std::make_shared<EndCell>(
			this->position.first,
			this->position.second
		);
	} else if (this->cell_type == "StartCell")
	{
		cell = std::make_shared<StartCell>(
			this->position.first,
			this->position.second
		);
	}
	if (this->enemy.get())
	{
		cell->setEnemy(
			this->enemy->load()
		);
	}
	if (this->item.get())
	{
		cell->setItem(
			this->item->load()
		);
	}
	return cell;
}

std::string CellSaver::getType() const
{
	return this->cell_type;
}
