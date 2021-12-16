#include "../../inc/exceptions/file_read_error.h"

FileReadError::FileReadError(
	const std::string& _unexpected
) noexcept:
	unexpected{_unexpected}
{}

std::string FileReadError::what() const
{
	std::string msg;
	msg = "File Read Error: \n";
	msg = msg + "Unable to read save file\n";
	if (this->unexpected != "")
		msg = msg + "Unexpected characters: \n\t" + this->unexpected + "\n";
	return msg;
}
