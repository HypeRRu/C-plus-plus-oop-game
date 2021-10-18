#include "../../inc/actions/game_observer.h"

GameObserver::GameObserver(const Game& game_object)
{
	this->field = game_object.getFieldPtr();
	this->renderer = game_object.getRendererPtr();
	this->player = game_object.getPlayerPtr();
}

GameObserver::~GameObserver()
{}

bool GameObserver::moveLogicForEnemy(ActionMove& action)
{
	if (this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	).getEnemy().get() != nullptr)
		return false;

	if (this->player->getX() == action.getCoords().first &&
		this->player->getY() == action.getCoords().second)
	{
		ActionAttack act(
			action.getEntity(),
			*this->player.get()
		);
		this->handleAction(act);
	}
	/* changing array */
	this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	).setEnemy(
		this->field->getCell(
			action.getEntity().getX(),
			action.getEntity().getY()
		).getEnemy()
	);
	this->field->getCell(
		action.getEntity().getX(),
		action.getEntity().getY()
	).setEnemy(nullptr);

	return true;
}

bool GameObserver::moveLogicForPlayer(ActionMove& action)
{
	Cell& target_cell = this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	);
	if (target_cell.getEnemy().get())
	{
		ActionAttack act(
			action.getEntity(),
			*target_cell.getEnemy().get()
		);
		this->handleAction(act);
		return false;
	}
	if (&target_cell.getItem())
	{
		ActionPickItem act(
			action.getEntity(),
			target_cell.getItem()
		);
		this->handleAction(act);
	}
	return true;
}

bool GameObserver::handleAction(ActionMove& action)
{
	Cell& target_cell = this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	);

	if (target_cell.getHasWall())
		return false;
	if (action.getIsEnemy())
	{
		if (!this->moveLogicForEnemy(action))
			return false;
	}
	else
	{
		if (!this->moveLogicForPlayer(action))
			return true;
	}

	action.getEntity().moveTo(
		action.getCoords().first,
		action.getCoords().second
	);
	ActionAddDrawable actDraw(action.getEntity());
	this->handleAction(actDraw);

	if (!action.getIsEnemy() && this->field->getEnd() == action.getCoords())
	{
		ActionPlayerReachEnd act;
		return this->handleAction(act);
	}
	return true;
}

bool GameObserver::handleAction(ActionAttack& action)
{
	size_t damage = action.getEntity1().getDamage();
	size_t shield = action.getEntity2().getShield();
	int dhealth = damage - shield;
	if (dhealth > 0)
		action.getEntity2().changeHealth(-dhealth);
	else
		return false;
	return true;
}

bool GameObserver::handleAction(ActionDeleteItem& action)
{
	this->renderer->removeObject(action.getItem());
	this->field->getCell(
		action.getItem().getX(),
		action.getItem().getY()
	).setItem(nullptr);
	return true;
}

bool GameObserver::handleAction(ActionDeleteEnemy& action)
{
	this->renderer->removeObject(action.getEnemy());
	this->field->getCell(
		action.getEnemy().getX(),
		action.getEnemy().getY()
	).setEnemy(nullptr);
	return true;
}

bool GameObserver::handleAction(ActionPickItem& action)
{
	if (!action.getEntity().canPickItem()) 
		return false;
	action.getItem().onPickUp(
		action.getEntity()
	);
	return true;
}

bool GameObserver::handleAction(ActionAddDrawable& action)
{
	this->renderer.get()->addObject(
		action.getDrawable(),
		60, 60,
		action.getIsBackground()
	);
	return true;
}

bool GameObserver::handleAction(ActionPlayerReachEnd& action)
{
	std::cout << "End reached!" << std::endl;
	return true;
}
