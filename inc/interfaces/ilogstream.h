#ifndef ILOGSTREAM_H
#define ILOGSTREAM_H

#include <ostream>
#include <memory>

class ILogStream
{
public:
	virtual std::ostream& getStream() const = 0;
	virtual std::shared_ptr<ILogStream> getStreamPtr() const = 0;
	virtual bool isStreamOpen() const = 0;
	virtual ~ILogStream() = default;
};

#endif
