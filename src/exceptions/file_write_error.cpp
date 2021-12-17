#include "../../inc/exceptions/file_write_error.h"

FileWriteError::FileWriteError() noexcept
{}

std::string FileWriteError::what() const
{
	std::string msg = "File Write Error: \n"; 
	msg = msg + "Unable to write in save file\n";
	return msg;
}
