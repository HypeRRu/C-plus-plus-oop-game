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
	std::ostream& getStream() const;

	bool isStreamOpen() const;
protected:
	std::ostream& stream;
};

#endif
