#ifndef BASE_VIEW_H
#define BASE_VIEW_H

#include "../interfaces/iview.h"

class BaseView: public IView
{
public:
	BaseView(size_t x = 0, size_t y = 0);
	virtual const std::string getTextureAlias() const = 0;
	virtual const size_t getX() const;
	virtual const size_t getY() const;
protected:
	size_t x, y;
};

#endif
