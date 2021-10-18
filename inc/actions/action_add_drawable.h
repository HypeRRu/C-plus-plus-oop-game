#ifndef ACTION_ADD_DRAWABLE_H
#define ACTION_ADD_DRAWABLE_H

#include "action.h"
#include "../interfaces/drawable.h"

class ActionAddDrawable: public Action
{
public:
	ActionAddDrawable(Drawable& _drawable, bool is_background_object = false);
	Drawable& getDrawable() const;
	bool getIsBackground() const;
protected:
	Drawable& drawable;
	bool is_background_object;
};

#endif
