#ifndef ACTION_ADD_DRAWABLE_H
#define ACTION_ADD_DRAWABLE_H

#include "action.h"
#include "../interfaces/drawable.h"

class ActionAddDrawable: public Action
{
public:
	ActionAddDrawable(Drawable& _drawable, bool is_background_object = false);
	ActionType getActionType();
	Drawable& getDrawable();
	bool getIsBackground();
protected:
	Drawable& drawable;
	bool is_background_object;
};

#endif
