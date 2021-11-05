#ifndef IMANAGER_H
#define IMANAGER_H

class Action;
class ActionMove;
class ActionAttack;
class ActionDeleteItem;
class ActionDeleteEnemy;
class ActionPickItem;
class ActionAddDrawable;
class ActionPlayerReachEnd;

class IManager
{
public:
	virtual bool handleAction(ActionMove& action) = 0;
	virtual bool handleAction(ActionAttack& action) = 0;
	virtual bool handleAction(ActionDeleteItem& action) = 0;
	virtual bool handleAction(ActionDeleteEnemy& action) = 0;
	virtual bool handleAction(ActionPickItem& action) = 0;
	virtual bool handleAction(ActionAddDrawable& action) = 0;
	virtual bool handleAction(ActionPlayerReachEnd& action) = 0;
};

#endif
