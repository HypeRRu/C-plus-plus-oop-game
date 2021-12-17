#include "../../inc/exceptions/parse_error.h"

ParseError::ParseError(
	const std::string& _object_name,
	const std::string& _fields_missing
) noexcept: 
	object_name{_object_name},
	missing_list{_fields_missing}
{}

std::string ParseError::what() const
{
	std::string msg;
	msg = "Parse Error: \n";
	msg = msg + "Unable to create object: " + this->object_name + "\n";
	msg = msg + "Required fields missing: \n" + this->missing_list + "\n";
	return msg;
}
