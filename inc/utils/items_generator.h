#ifndef ITEMS_GENERATOR_H
#define ITEMS_GENERATOR_H


#include "../field.h"
#include "../items/base_item.h"
#include "../items/heal_item.h"
#include "../items/shield_item.h"
#include "../items/weapon_item.h"

#include <ctime>
#include <cstdlib>
#include <map>


using item_sptr = std::shared_ptr<BaseItem>;

class ItemsGenerator
{
public:
	ItemsGenerator(const Field& _field, double item_chance = 0.02);
	~ItemsGenerator() = default;

	std::map<std::pair<size_t, size_t>, item_sptr> generateItems();
protected:
	const Field& field;
	double item_chance;
};

#endif
