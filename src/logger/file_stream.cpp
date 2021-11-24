#include "../../inc/logger/file_stream.h"

FileStream::FileStream(const std::string& filepath):
	stream{std::make_shared<std::ofstream>()}
{
	this->stream->open(filepath, std::ios::app);
	if (!this->isStreamOpen())
		return;
	*this->stream.get() << "\t\t[FILE LOG STARTED]\n";
}

FileStream::~FileStream()
{
	if (this->isStreamOpen())
	{
		*this->stream.get() << "\t\t[FILE LOG ENDED]\n";
		this->stream.get()->close();
	}
}

std::shared_ptr<ILogStream> FileStream::getStreamPtr() const
{
	return std::make_shared<FileStream>(*this);
}

bool FileStream::isStreamOpen() const
{
	return this->stream.get()->is_open();
}

void FileStream::writeLog(const std::string& log)
{
	if (this->isStreamOpen())
		*this->stream.get() << log;
}
