#include "../../inc/saves/enemy_saver.h"

EnemySaver::EnemySaver(
	std::pair<size_t, size_t> _position,
	int _health,
	int _shield,
	int _damage,
	int _money_picked,
	const std::string& _enemy_type
):	enemy_type{_enemy_type}, position{_position},
	health{_health}, shield{_shield}, 
	damage{_damage}, money_picked{_money_picked}
{
	this->offset = "\t\t";
}

EnemySaver::EnemySaver(std::istringstream& stream):
	money_picked{0},
	position_set{false}
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
			this->enemy_type = parameter_str;
		} else if (left_op == "position")
		{
			block >> parameter_pair;
			this->position = parameter_pair;
			this->position_set = true;
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
	this->checkParams();
}

void EnemySaver::checkParams() const
{
	std::string missing_params = "";
	if (this->enemy_type == "")
		missing_params += "type\n";
	if (!this->position_set)
		missing_params += "position\n";
	if (missing_params != "")
		throw ParseError{"Enemy", missing_params};

	if (this->damage <= 0)
		throw GameLogicError{"Enemy damage must be greater than 0"};
	if (this->shield < 0)
		throw GameLogicError{"Enemy shield cannot be less than 0"};
	if (this->health <= 0)
		throw GameLogicError{"Enemy health must be greater than 0"};
}

std::string EnemySaver::save() const
{
	std::string line_offset = this->offset+"\t";
	std::stringstream buffer;
	buffer << "[" << std::endl;
	buffer << line_offset << "type=" << this->enemy_type << std::endl;
	buffer << line_offset << "position=" << this->position << std::endl;
	buffer << line_offset << "health=" << this->health << std::endl;
	buffer << line_offset << "shield=" << this->shield << std::endl;
	buffer << line_offset << "damage=" << this->damage << std::endl;
	buffer << line_offset << "money=" << this->money_picked << std::endl;
	buffer << this->offset + "]";
 	return buffer.str();
}

std::shared_ptr<BaseEnemy> EnemySaver::load() const
{
	std::shared_ptr<BaseEnemy> enemy;
	if (this->enemy_type == "RegularEnemy")
	{
		enemy = std::make_shared<RegularEnemy>(
			this->position.first,
			this->position.second
		);
	} else if (this->enemy_type == "DaemonEnemy")
	{
		enemy = std::make_shared<DaemonEnemy>(
			this->position.first,
			this->position.second
		);
	} else if (this->enemy_type == "GargoyleEnemy")
	{
		enemy = std::make_shared<GargoyleEnemy>(
			this->position.first,
			this->position.second
		);
	} else
		throw FileReadError{this->enemy_type};

	if (!enemy.get())
		throw GameLogicError{"Unable to create enemy instance!"};
	enemy->changeHealth(
		this->health - enemy->getHealth()
	);
	enemy->changeShield(
		this->shield - enemy->getShield()
	);
	enemy->changeDamage(
		this->damage - enemy->getDamage()
	);
	enemy->changeMoneyPicked(
		this->money_picked - enemy->getMoneyPicked()
	);
	return enemy;
}
