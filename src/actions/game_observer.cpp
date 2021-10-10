#include "../../inc/actions/game_observer.h"

#include <iostream>
#include <cstdio>
GameObserver::GameObserver(const Game& game_object)
{
	std::cout << "GO created" << std::endl;

	this->field = game_object.getFieldPtr();
	this->renderer = game_object.getRendererPtr();
	this->player = game_object.getPlayerPtr();
}

void GameObserver::setEnemies(std::map<std::pair<size_t, size_t>, enemy_sptr> enemies)
{
	this->enemies = enemies;
}

GameObserver::~GameObserver()
{
	std::cout << "GO deleted" << std::endl;
}

bool GameObserver::handleAction(Action& action)
{
	switch (action.getActionType())
	{
		case ActionType::moveAction:
			return this->handleActionMove(action);
			break;
		case ActionType::effectAction:
			return this->handleActionEffect(action);
			break;
		case ActionType::attackAction:
			return this->handleActionAttack(action);
			break;
		case ActionType::deleteItemAction:
			return this->handleActionDeleteItem(action);
			break;
		case ActionType::deleteEnemyAction:
			return this->handleActionDeleteEnemy(action);
			break;
		case ActionType::pickItemAction:
			return this->handleActionPickItem(action);
			break;
		case ActionType::addItemAction:
			return this->handleActionAddItem(action);
			break;
		case ActionType::addEnemyAction:
			return this->handleActionAddEnemy(action);
			break;

		case ActionType::defaultAction:
		default:
			break;
	}
	return false;
}

bool GameObserver::handleActionMove(Action& _action)
{
	ActionMove& action = dynamic_cast<ActionMove&>(_action);
	Cell& target_cell = this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	);
	if (target_cell.getHasWall())
		return false;
	if (this->enemies.find(action.getCoords()) != this->enemies.end())
	{
		ActionAttack act(
			action.getEntity(),
			*this->enemies.at(action.getCoords()).get()
		);
		return this->handleAction(act);
	}
	if (&target_cell.getItem())
	{
		ActionPickItem act(
			action.getEntity(),
			target_cell.getItem()
		);
		this->handleAction(act);
	}

	action.getEntity().moveTo(
		action.getCoords().first,
		action.getCoords().second
	);
	return true;
}

bool GameObserver::handleActionEffect(Action& _action)
{
	// ActionEffect& action = dynamic_cast<ActionEffect&>(_action);
	return true;
}

bool GameObserver::handleActionAttack(Action& _action)
{
	ActionAttack& action = dynamic_cast<ActionAttack&>(_action);
	size_t damage = action.getEntity1().getDamage();
	size_t shield = action.getEntity2().getShield();
	size_t dhealth = damage - shield;
	if (dhealth > 0)
		action.getEntity2().decreaseHealth(dhealth);
	else
		return false;
	return true;
}

bool GameObserver::handleActionDeleteItem(Action& _action)
{
	ActionDeleteItem& action = dynamic_cast<ActionDeleteItem&>(_action);
	this->renderer->removeObject(action.getItem());
	return true;
}

bool GameObserver::handleActionDeleteEnemy(Action& _action)
{
	ActionDeleteEnemy& action = dynamic_cast<ActionDeleteEnemy&>(_action);
	this->renderer->removeObject(action.getEnemy());
	return true;
}

bool GameObserver::handleActionPickItem(Action& _action)
{
	ActionPickItem& action = dynamic_cast<ActionPickItem&>(_action);
	std::cout << "Item picked" << std::endl;
	action.getItem().onPickUp(
		action.getEntity()
	);
	return true;
}

bool GameObserver::handleActionAddItem(Action& _action)
{
	ActionAddItem& action = dynamic_cast<ActionAddItem&>(_action);
	this->renderer.get()->addObject(
		action.getItem(),
		60, 60,
		false
	);
	return true;
}

bool GameObserver::handleActionAddEnemy(Action& _action)
{
	ActionAddEnemy& action = dynamic_cast<ActionAddEnemy&>(_action);
	this->renderer.get()->addObject(
		action.getEnemy(),
		60, 60,
		false
	);
	return true;
}
