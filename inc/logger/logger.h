#ifndef LOGGER_H
#define LOGGER_H

#include "../interfaces/imanager.h"
#include "../interfaces/ilogstream.h"

#include "../actions/action.h"
#include "../actions/action_add_drawable.h"
#include "../actions/action_move.h"
#include "../actions/action_pick_item.h"
#include "../actions/action_attack.h"
#include "../actions/action_delete_item.h"
#include "../actions/action_delete_enemy.h"
#include "../actions/action_player_reach_end.h"
#include "../actions/base_observed.h"
#include "operators.h"

#include "console_stream.h"

#include <map>
#include <string>
#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <functional>
#include <sstream>

class Logger: public IManager
{
public:
	using stream_ptr = std::shared_ptr<ILogStream>;

	static Logger& instance();

	Logger(const Logger&) = delete;
	Logger& operator =(const Logger&) = delete;

	bool handleAction(ActionMove& action);
	bool handleAction(ActionAttack& action);
	bool handleAction(ActionDeleteItem& action);
	bool handleAction(ActionDeleteEnemy& action);
	bool handleAction(ActionPickItem& action);
	bool handleAction(ActionAddDrawable& action);
	bool handleAction(ActionPlayerReachEnd& action);

	void write(const std::string& log);

	void addStream(stream_ptr stream, const std::string& key = "default");
	void removeStream(const std::string& key);

	void subscribeObject(const BaseObserved& object);
	void unsubscribeObject(const BaseObserved& object);

	void setLogAll(bool state);
protected:
	Logger();

	bool checkSubcriber(const BaseObserved& object);
	std::map<std::string, stream_ptr> log_streams;
	std::vector<std::reference_wrapper<const BaseObserved>> subscribers;

	bool log_all;
};

#endif
