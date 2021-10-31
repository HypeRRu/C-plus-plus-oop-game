#include "../../inc/logger/operators.h"

std::ostream& operator <<(std::ostream& stream, const BaseEntity& object)
{
	stream << "[ENTITY][" << object.getX() << "; " << object.getY() << "]";
	if (dynamic_cast<const Player*>(&object))
	{
		stream << "[PLAYER]";
	}
	
	return stream;
}

std::ostream& operator <<(std::ostream& stream, const BaseItem& object)
{
	stream << "[ITEM][" << object.getX() << "; " << object.getY() << "]";
	return stream;
}

std::ostream& operator <<(std::ostream& stream, const std::pair<size_t, size_t>& object)
{
	stream << "(" << object.first << "; " << object.second << ")";
	return stream;
}
