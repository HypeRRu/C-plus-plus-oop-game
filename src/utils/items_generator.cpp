#include "../../inc/utils/items_generator.h"

ItemsGenerator::ItemsGenerator(const Field& _field, double item_chance):
	field{_field}, item_chance{item_chance}
{}

std::map<std::pair<size_t, size_t>, item_sptr> ItemsGenerator::generateItems()
{
	std::srand(std::time(NULL));

	std::map<std::pair<size_t, size_t>, item_sptr> items;
	item_sptr _item;
	int item_offset = (int) (1 / this->item_chance);
	int item_type;
	bool has_item;

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

			has_item = (std::rand() % item_offset) == 0;
			if (has_item)
			{
				item_type = std::rand() % 3;
				switch(item_type)
				{
					case 0:
						/* Heal item */
						_item = std::make_shared<HealItem>(x, y);
						break;
					case 1:
						/* Shield item */
						_item = std::make_shared<ShieldItem>(x, y);
						break;
					case 2:
						/* Weapon item */
						_item = std::make_shared<WeaponItem>(x, y);
						break;
					default:
						break;
				}
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
