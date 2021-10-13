#include "../../inc/actions/action_add_drawable.h"

ActionAddDrawable::ActionAddDrawable(Drawable& _drawable, bool is_background_object): 
	drawable{_drawable}, is_background_object{is_background_object}
{}
	
ActionType ActionAddDrawable::getActionType()
{
	return ActionType::addDrawableAction;
}

bool ActionAddDrawable::getIsBackground() const
{
	return this->is_background_object;
}

Drawable& ActionAddDrawable::getDrawable() const
{
	return this->drawable;
}
