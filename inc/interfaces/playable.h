#ifndef PLAYABLE_H
#define PLAYABLE_H

class Playable
{
public:
	virtual void pickItem()   = 0;
	virtual void onReachEnd() = 0;
};

#endif