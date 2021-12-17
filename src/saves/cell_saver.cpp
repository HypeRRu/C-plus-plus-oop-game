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

CellSaver::CellSaver(std::istringstream& stream):
	wall{0},
	position_set{false}
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
			this->position_set = true;
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
	this->checkParams();
}

void CellSaver::checkParams() const
{
	std::string missing_params = "";
	if (this->cell_type == "")
		missing_params += "type\n";
	if (!this->position_set)
		missing_params += "position\n";
	if (missing_params != "")
		throw ParseError{"Cell", missing_params};
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
	} else
		throw FileReadError{this->cell_type};

	if (!cell.get())
		throw GameLogicError{"Unable to create cell instance!"};
	if (this->enemy.get())
	{
		std::shared_ptr<BaseEnemy> en = this->enemy->load();
		if (
			cell->getX() != en->getX() ||
			cell->getY() != en->getY()
		)
			throw GameLogicError{"Enemy coordinates must be same as cell coords"};
		cell->setEnemy(
			en
		);
	}
	if (this->item.get())
	{
		std::shared_ptr<BaseItem> it = this->item->load();
		if (
			cell->getX() != it->getX() ||
			cell->getY() != it->getY()
		)
			throw GameLogicError{"Item coordinates must be same as cell coords"};
		cell->setItem(
			it
		);
	}
	if (
		this->wall && 
		(this->item.get() || this->enemy.get())
	)
		throw GameLogicError{"Item and enemy cannot be\n in wall cell"};
	return cell;
}

std::string CellSaver::getType() const
{
	return this->cell_type;
}
