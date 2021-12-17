#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include <sstream>
#include "../entities/base_entity.h"
#include "../entities/player.h"
#include "../items/base_item.h"

class BaseEntity;
class BaseItem;
class Cell;
class EndCell;
class StartCell;

std::ostream& operator <<(std::ostream& stream, const BaseEntity& object);
std::ostream& operator <<(std::ostream& stream, const BaseItem& object);
std::ostream& operator <<(std::ostream& stream, const std::pair<size_t, size_t>& object);
std::istream& operator >>(std::istream& stream, std::pair<size_t, size_t>& object);

#endif
