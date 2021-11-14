#ifndef ACTION_ADD_DRAWABLE_H
#define ACTION_ADD_DRAWABLE_H

#include "action.h"
#include "../interfaces/drawable.h"

class ActionAddDrawable: public Action
{
public:
	ActionAddDrawable(Drawable& _drawable, size_t draw_layer = 0);
	Drawable& getDrawable() const;
	size_t getDrawLayer() const;
protected:
	Drawable& drawable;
	size_t draw_layer;
};

#endif
