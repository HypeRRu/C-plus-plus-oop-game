#ifndef BASE_ITEM_VIEW_H
#define BASE_ITEM_VIEW_H

#include "base_view.h"

class BaseItemView: public BaseView
{
public:
	BaseItemView(size_t x = 0, size_t y = 0);
	virtual const std::string getTextureAlias() const = 0;
};

#endif
