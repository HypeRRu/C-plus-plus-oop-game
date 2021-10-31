#include "../../inc/logger/logger.h"

Logger& Logger::instance()
{
	static Logger logger_instance;
	return logger_instance;
}

Logger::Logger(): log_all{false}
{
	this->log_streams["default"] = std::make_shared<ConsoleStream>();
}

void Logger::addStream(stream_ptr stream, const std::string& key)
{
	this->log_streams.insert_or_assign(key, stream);
}

void Logger::removeStream(const std::string& key)
{
	if (this->log_streams.find(key) != this->log_streams.end())
		this->log_streams.erase(key);
}

void Logger::subscribeObject(const BaseObserved& object)
{
	for (auto& subscriber: this->subscribers)
	{
		if (subscriber.get() == object)
			return;
	}
	this->subscribers.push_back(std::ref(object));
}

void Logger::unsubscribeObject(const BaseObserved& object)
{
	for (size_t i = 0; i < this->subscribers.size(); ++i)
	{
		if (this->subscribers[i].get() == object)
		{
			this->subscribers.erase(this->subscribers.begin() + i);
			return;
		}
	}
}

bool Logger::checkSubcriber(const BaseObserved& object)
{
	for (auto& subscriber: this->subscribers)
	{
		if (subscriber.get() == object)
			return true;
	}
	return false;
}

void Logger::setLogAll(bool state)
{
	this->log_all = state;
}

void Logger::write(const std::string& log)
{
	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
		stream.second->writeLog(log);
}


bool Logger::handleAction(ActionMove& action)
{
	if (
		!this->log_all &&
		!this->checkSubcriber(action.getEntity())
	)
		return false;

	std::stringstream buffer;
	buffer << action.getEntity()
		<< " moved to "
		<< action.getCoords() 
		<< std::endl;
	
	this->write(buffer.str());
	return true;
}

bool Logger::handleAction(ActionAttack& action)
{
	if (
		!this->log_all &&
		!this->checkSubcriber(action.getEntity1()) &&
		!this->checkSubcriber(action.getEntity2())
	)
		return false;

	std::stringstream buffer;
	buffer << action.getEntity1() 
		<< " attacked " << action.getEntity2()
		<< " and caused " << action.getDamageCaused() << "dmg"
		<< ", hp left: " << action.getEntity2().getHealth() - action.getDamageCaused()
		<< std::endl;

	this->write(buffer.str());
	return true;
}

bool Logger::handleAction(ActionDeleteItem& action)
{
	if (
		!this->log_all &&
		!this->checkSubcriber(action.getItem())
	)
		return false;

	std::stringstream buffer;
	buffer << action.getItem() 
		<< " deleted"
		<< std::endl;

	this->write(buffer.str());
	return true;
}

bool Logger::handleAction(ActionDeleteEnemy& action)
{
	if (
		!this->log_all && 
		!this->checkSubcriber(action.getEnemy())
	)
		return false;

	std::stringstream buffer;
	buffer << action.getEnemy() 
		<< " deleted"
		<< std::endl;

	this->write(buffer.str());
	return true;
}

bool Logger::handleAction(ActionPickItem& action)
{
	if (
		!this->log_all && 
		!this->checkSubcriber(action.getEntity()) &&
		!this->checkSubcriber(action.getItem())
	)
		return false;

	std::string item_type;
	std::string item_effect;
	int characteristic = 0;
	auto& item = action.getItem();
	switch (item.getItemType())
	{
		case ItemType::HealItem:
			item_type = "[HEAL ITEM]";
			item_effect = "hp changed to ";
			characteristic = action.getEntity().getHealth();
			break;
		case ItemType::ShieldItem:
			item_type = "[SHIELD ITEM]";
			item_effect = "shield changed to ";
			characteristic = action.getEntity().getShield();
			break;
		case ItemType::WeaponItem:
			item_type = "[WEAPON ITEM]";
			item_effect = "damage changed to ";
			characteristic = action.getEntity().getDamage();
			break;
		default:
			item_type = "[DEFAULT ITEM]";
			break;
	}
	characteristic += item.getEffect();

	std::stringstream buffer;
	buffer << action.getEntity() 
		<< " picked "
		<< item << item_type
		<< ", " << item_effect << characteristic
		<< std::endl;

	this->write(buffer.str());
	return true;
}

bool Logger::handleAction(ActionAddDrawable& action)
{
	// this->write();
	return true;
}

bool Logger::handleAction(ActionPlayerReachEnd& action)
{
	if (
		!this->log_all && 
		!this->checkSubcriber(action.getEntity())
	)
		return false;

	std::stringstream buffer;
	buffer << action.getEntity()
		<< " reached end cell "
		<< action.getCoords() 
		<< std::endl;

	this->write(buffer.str());
	return true;
}
