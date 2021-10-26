#include "../../inc/logger/file_stream.h"

FileStream::FileStream(const std::string& filepath):
	stream{std::make_shared<std::ofstream>()}
{
	this->stream->open(filepath, std::ios::out);
	if (!this->isStreamOpen())
		return;
	this->getStream() << "\t\t[FILE LOG STARTED]\n";
}

FileStream::~FileStream()
{
	if (this->isStreamOpen())
	{
		this->getStream() << "\t\t[FILE LOG ENDED]\n";
		this->stream.get()->close();
	}
}

std::shared_ptr<ILogStream> FileStream::getStreamPtr() const
{
	return std::make_shared<FileStream>(*this);
}

std::ostream& FileStream::getStream() const
{
	return *this->stream.get();
}

bool FileStream::isStreamOpen() const
{
	return this->stream.get()->is_open();
}
