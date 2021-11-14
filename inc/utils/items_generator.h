#ifndef ITEMS_GENERATOR_H
#define ITEMS_GENERATOR_H

#include "../game_config.h"
#include "random_stuff_generator.h"

#include "../field.h"
#include "../items/base_item.h"
#include "../items/heal_item.h"
#include "../items/shield_item.h"
#include "../items/weapon_item.h"
#include "../items/coin_item.h"

#include <map>

using item_sptr = std::shared_ptr<BaseItem>;

template<typename ...items_types>
class ItemsGenerator
{
public:
	ItemsGenerator(const Field& _field): field{_field}
	{}
	~ItemsGenerator() = default;

	std::map<std::pair<size_t, size_t>, item_sptr> generateItems()
	{
		std::map<std::pair<size_t, size_t>, item_sptr> items;
		item_sptr _item;
		int item_type;
		bool has_item;
		int types_cnt = sizeof...(items_types);

		int walls_count = 0;
		for (size_t y = 0; y < this->field.getHeight(); y++)
		{
			for (size_t x = 0; x < this->field.getWidth(); x++)
			{
				if (this->field.getCell(x, y).getHasWall())
					++walls_count;
			}
		}
		int possibilities = this->field.getHeight() * this->field.getWidth() - walls_count - 2;
		RandomStuffGenerator generator(
			GameConfig::instance().getItemsCount(),
			possibilities
		);

		for (size_t y = 0; y < this->field.getHeight(); y++)
		{
			for (size_t x = 0; x < this->field.getWidth(); x++)
			{
				if (
					(x == this->field.getStart().first && y == this->field.getStart().second) ||
					(x == this->field.getEnd().first && y == this->field.getEnd().second)
				)
					continue;
				if (this->field.getCell(x, y).getHasWall()) 
					continue;

				has_item = generator.generateNew();
				if (has_item)
				{
					std::srand(std::time(NULL) + y * this->field.getWidth() + x);
					item_type = std::rand() % types_cnt;
					// std::vector<item_sptr> itypes = {std::forward<item_sptr>(std::make_shared<items_types>(x, y))...};
					std::vector<item_sptr> itypes = {std::make_shared<items_types>(x, y)...};
					_item = itypes.at(item_type);
					items.insert(std::pair<std::pair<size_t, size_t>, item_sptr>
						{
							std::pair<size_t, size_t>{x, y},
							_item
						}
					);
				}
			}
		}

		return items;
	}
protected:
	const Field& field;
};

template<>
class ItemsGenerator<>
{
public:
	ItemsGenerator(const Field& _field): generator{_field}
	{}
	~ItemsGenerator() = default;

	std::map<std::pair<size_t, size_t>, item_sptr> generateItems()
	{
		return generator.generateItems();
	}
protected:
	ItemsGenerator<HealItem, WeaponItem, ShieldItem, CoinItem> generator;
};



#endif
