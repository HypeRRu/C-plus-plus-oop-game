#include "../../inc/actions/action_add_drawable.h"

ActionAddDrawable::ActionAddDrawable(Drawable& _drawable, size_t draw_layer): 
	drawable{_drawable}, draw_layer{draw_layer}
{}

size_t ActionAddDrawable::getDrawLayer() const
{
	return this->draw_layer;
}

Drawable& ActionAddDrawable::getDrawable() const
{
	return this->drawable;
}
