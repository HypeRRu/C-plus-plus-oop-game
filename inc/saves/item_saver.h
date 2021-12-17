#ifndef ITEM_SAVER_H
#define ITEM_SAVER_H

#include <string>
#include <memory>

#include "../items/base_item.h"
#include "../items/coin_item.h"
#include "../items/heal_item.h"
#include "../items/shield_item.h"
#include "../items/weapon_item.h"
#include "../interfaces/saver.h"

class ItemSaver: public Saver
{
public:
	ItemSaver(
		std::pair<size_t, size_t> _position,
		int _effect,
		const std::string& _item_type
	);

	void checkParams() const;

	ItemSaver(
		std::istringstream& stream
	);

	~ItemSaver() = default;

	std::string save() const;
	std::shared_ptr<BaseItem> load() const;
protected:
	std::string item_type;
	std::pair<size_t, size_t> position;
	int effect;

	std::string offset;

	bool position_set;
};

#endif