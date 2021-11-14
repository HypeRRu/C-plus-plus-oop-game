#ifndef ITEMS_COUNT_CONFIGURATION_H
#define ITEMS_COUNT_CONFIGURATION_H

#include "../interfaces/configuration.h"

template<int cnt>
class ItemsCountConfiguration: public Configuration
{
public:
	bool exec(GameConfig& config) const
	{
		config.setItemsCount(cnt);
		return true;
	}
};

#endif