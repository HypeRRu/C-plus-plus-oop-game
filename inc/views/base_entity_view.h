#ifndef BASE_ENTITY_VIEW_H
#define BASE_ENTITY_VIEW_H

#include "base_view.h"

class BaseEntityView: public BaseView
{
public:
	BaseEntityView(size_t x = 0, size_t y = 0);
	virtual const std::string getTextureAlias() const = 0;
};

#endif
