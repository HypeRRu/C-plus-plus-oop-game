#include "../../inc/saves/item_saver.h"

ItemSaver::ItemSaver(
	std::pair<size_t, size_t> _position,
	int _effect,
	const std::string& _item_type
):	item_type{_item_type}, position{_position},
	effect{_effect}
{
	this->offset = "\t\t";
}

ItemSaver::ItemSaver(std::istringstream& stream)
{
	this->offset = "\t\t";
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
			this->item_type = parameter_str;
		} else if (left_op == "position")
		{
			block >> parameter_pair;
			this->position = parameter_pair;
		}
		else if (left_op == "effect")
		{
			block >> parameter_int;
			this->effect = parameter_int;
		}
	}
}

std::string ItemSaver::save() const
{
	std::string line_offset = this->offset+"\t";
	std::stringstream buffer;
	buffer << "[" << std::endl;
	buffer << line_offset << "type=" << this->item_type << std::endl;
	buffer << line_offset << "position=" << this->position << std::endl;
	buffer << line_offset << "effect=" << this->effect << std::endl;
	buffer << this->offset+"]";
 	return buffer.str();
}

std::shared_ptr<BaseItem> ItemSaver::load() const
{
	std::shared_ptr<BaseItem> item;
	if (this->item_type == "CoinItem")
	{
		item = std::make_shared<CoinItem>(
			this->position.first,
			this->position.second,
			this->effect
		);
	} else if (this->item_type == "HealItem")
	{
		item = std::make_shared<HealItem>(
			this->position.first,
			this->position.second,
			this->effect
		);
	} else if (this->item_type == "ShieldItem")
	{
		item = std::make_shared<ShieldItem>(
			this->position.first,
			this->position.second,
			this->effect
		);
	} else if (this->item_type == "WeaponItem")
	{
		item = std::make_shared<WeaponItem>(
			this->position.first,
			this->position.second,
			this->effect
		);
	}
	return item;
}
