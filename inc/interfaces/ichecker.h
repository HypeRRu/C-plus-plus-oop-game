#ifndef ICHECKER_H
#define ICHECKER_H

class GameRule;
class StateGameplay;

class IChecker
{
public:
	virtual bool checkRule(StateGameplay& state) const = 0;
};

#endif