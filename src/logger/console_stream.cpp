#include "../../inc/logger/console_stream.h"

ConsoleStream::ConsoleStream(): stream{std::cout}
{
	this->stream << "\t\t[CONSOLE LOG STARTED]\n";
}

ConsoleStream::~ConsoleStream()
{
	this->stream << "\t\t[CONSOLE LOG ENDED]\n";
}

std::shared_ptr<ILogStream> ConsoleStream::getStreamPtr() const
{
	return std::make_shared<ConsoleStream>(*this);
}

bool ConsoleStream::isStreamOpen() const
{
	return true;
}

void ConsoleStream::writeLog(const std::string& log)
{
	if (this->isStreamOpen())
		this->stream << log;
}
