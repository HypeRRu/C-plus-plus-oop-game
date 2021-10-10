#ifndef ACTION_EFFECT_H
#define ACTION_EFFECT_H

#include "action.h"

class ActionEffect: public Action
{
public:
	ActionEffect();
	ActionType getActionType();
protected:
	/* context */
};

#endif
