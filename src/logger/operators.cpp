#include "../../inc/logger/operators.h"

std::ostream& operator <<(std::ostream& stream, const BaseEntity& object)
{
	stream << "[ENTITY][" << &object << "]";
	if (dynamic_cast<const Player*>(&object))
	{
		stream << "[PLAYER]";
	} else
	{
		stream << "";
	}
	
	return stream;
}

std::ostream& operator <<(std::ostream& stream, const BaseItem& object)
{
	stream << "[ITEM][" << &object << "]";
	return stream;
}

std::ostream& operator <<(std::ostream& stream, const std::pair<size_t, size_t>& object)
{
	stream << "(" << object.first << "; " << object.second << ")";
	return stream;
}
