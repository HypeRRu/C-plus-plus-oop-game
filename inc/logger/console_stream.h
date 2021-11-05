#ifndef CONSOLE_STREAM_H
#define CONSOLE_STREAM_H

#include "../interfaces/ilogstream.h"
#include <iostream>

class ConsoleStream: public ILogStream
{
public:
	ConsoleStream();
	~ConsoleStream();

	std::shared_ptr<ILogStream> getStreamPtr() const;

	bool isStreamOpen() const;
	void writeLog(const std::string& log);
protected:
	std::ostream& stream;
};

#endif
