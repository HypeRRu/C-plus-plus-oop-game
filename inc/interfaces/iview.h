#ifndef IVIEW_H
#define IVIEW_H

#include <string>

class IView
{
public:
	virtual const std::string getTextureAlias() const = 0;
};

#endif
