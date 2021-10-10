#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <string>

class Drawable
{
public:
	virtual const std::string getTextureAlias() const = 0;
	virtual const size_t getX() const = 0;
	virtual const size_t getY() const = 0;
};

#endif