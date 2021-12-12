#ifndef CELL_SAVER_H
#define CELL_SAVER_H

#include <string>
#include <memory>

#include "../cells/cell.h"
#include "../cells/end_cell.h"
#include "../cells/start_cell.h"
#include "../interfaces/saver.h"
#include "enemy_saver.h"
#include "item_saver.h"

class Cell;
class EndCell;
class StartCell;

class CellSaver
{
public:
	CellSaver(
		std::pair<size_t, size_t> _position,
		bool _wall,
		std::weak_ptr<BaseEnemy> _enemy,
		std::weak_ptr<BaseItem> _item,
		const std::string& _cell_type = "Cell"
	);

	CellSaver(
		std::istringstream& stream
	);

	~CellSaver() = default;

	std::string save() const;
	std::shared_ptr<Cell> load() const;

	std::string getType() const;
protected:
	std::string cell_type;
	std::pair<size_t, size_t> position;
	bool wall;

	std::shared_ptr<EnemySaver> enemy;
	std::shared_ptr<ItemSaver> item;

	std::string offset;
};

#endif