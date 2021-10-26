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


bool Logger::handleAction(ActionMove& action)
{
	if (
		!this->log_all &&
		!this->checkSubcriber(action.getEntity())
	)
		return false;

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getEntity()
			<< " moved to "
			<< action.getCoords() 
			<< std::endl;
	}
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

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getEntity1() 
			<< " attacked " << action.getEntity2()
			<< " and caused " << action.getDamageCaused() << "dmg"
			<< ", hp left: " << action.getEntity2().getHealth() - action.getDamageCaused()
			<< std::endl;
	}
	return true;
}

bool Logger::handleAction(ActionDeleteItem& action)
{
	if (
		!this->log_all &&
		!this->checkSubcriber(action.getItem())
	)
		return false;

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getItem() 
			<< " deleted"
			<< std::endl;
	}
	return true;
}

bool Logger::handleAction(ActionDeleteEnemy& action)
{
	if (
		!this->log_all && 
		!this->checkSubcriber(action.getEnemy())
	)
		return false;

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getEnemy() 
			<< " deleted"
			<< std::endl;
	}
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

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getEntity() 
			<< " picked "
			<< item << item_type
			<< ", " << item_effect << characteristic
			<< std::endl;
	}
	return true;
}

bool Logger::handleAction(ActionAddDrawable& action)
{
	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
	}
	return true;
}

bool Logger::handleAction(ActionPlayerReachEnd& action)
{
	if (
		!this->log_all && 
		!this->checkSubcriber(action.getEntity())
	)
		return false;

	for (std::pair<std::string, stream_ptr> stream: this->log_streams)
	{
		if (!stream.second->isStreamOpen())
			continue;
		stream.second->getStream() << action.getEntity()
			<< " reached end cell "
			<< action.getCoords() 
			<< std::endl;
	}
	return true;
}
