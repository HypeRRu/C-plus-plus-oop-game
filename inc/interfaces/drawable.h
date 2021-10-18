#ifndef DRAWABLE_H
#define DRAWABLE_H

#include "iview.h"
#include <memory>

class Drawable
{
public:
	virtual const IView& getView() const = 0;
	virtual void setView(std::shared_ptr<IView> _view) = 0;
	virtual const size_t getX() const = 0;
	virtual const size_t getY() const = 0;
};

#endif
