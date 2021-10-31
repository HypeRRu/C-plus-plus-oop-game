#ifndef FILE_STREAM_H
#define FILE_STREAM_H

#include <string>
#include <fstream>
#include <memory>
#include "../interfaces/ilogstream.h"

class FileStream: public ILogStream
{
public:
	FileStream(const std::string& filepath);
	~FileStream();

	std::shared_ptr<ILogStream> getStreamPtr() const;

	bool isStreamOpen() const;
	void writeLog(const std::string& log);
protected:
	std::shared_ptr<std::ofstream> stream;
};

#endif
