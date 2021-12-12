#include "../../inc/saves/player_saver.h"

PlayerSaver::PlayerSaver(
	std::pair<size_t, size_t> _position,
	int _health,
	int _shield,
	int _damage,
	int _money_picked
):	position{_position},
	health{_health}, shield{_shield}, 
	damage{_damage}, money_picked{_money_picked}
{
	this->offset = "";
}

PlayerSaver::PlayerSaver(std::istringstream& stream)
{
	this->offset = "";
	// parse string
	std::string line = "";
	std::string left_op;
	int parameter_int;
	std::pair<size_t, size_t> parameter_pair;
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
		if (left_op == "position")
		{
			block >> parameter_pair;
			this->position = parameter_pair;
		}
		else if (left_op == "health")
		{
			block >> parameter_int;
			this->health = parameter_int;
		}
		else if (left_op == "shield")
		{
			block >> parameter_int;
			this->shield = parameter_int;
		} else if (left_op == "damage")
		{
			block >> parameter_int;
			this->damage = parameter_int;
		} else if (left_op == "money")
		{
			block >> parameter_int;
			this->money_picked = parameter_int;
		}
	}
}

std::string PlayerSaver::save() const
{
	std::string line_offset = this->offset+"\t";
	std::stringstream buffer;
	buffer << "[" << std::endl;
	buffer << line_offset << "position=" << this->position << std::endl;
	buffer << line_offset << "health=" << this->health << std::endl;
	buffer << line_offset << "shield=" << this->shield << std::endl;
	buffer << line_offset << "damage=" << this->damage << std::endl;
	buffer << line_offset << "money=" << this->money_picked << std::endl;
	buffer << this->offset << "]";
 	return buffer.str();
}

std::shared_ptr<Player> PlayerSaver::load() const
{
	std::shared_ptr<Player> player;
	player = std::make_shared<Player>(
		this->position.first,
		this->position.second
	);
	player->changeHealth(
		this->health - player->getHealth()
	);
	player->changeShield(
		this->shield - player->getShield()
	);
	player->changeDamage(
		this->damage - player->getDamage()
	);
	player->changeMoneyPicked(
		this->money_picked - player->getMoneyPicked()
	);
	return player;
}
