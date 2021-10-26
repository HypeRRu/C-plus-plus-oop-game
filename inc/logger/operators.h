#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include "../entities/base_entity.h"
#include "../entities/player.h"
#include "../items/base_item.h"

std::ostream& operator <<(std::ostream& stream, const BaseEntity& object);
std::ostream& operator <<(std::ostream& stream, const BaseItem& object);
std::ostream& operator <<(std::ostream& stream, const std::pair<size_t, size_t>& object);

#endif
