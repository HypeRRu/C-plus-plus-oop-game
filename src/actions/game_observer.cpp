#include "../../inc/actions/game_observer.h"

GameObserver::GameObserver(const Game& game_object)
{
	this->field = game_object.getFieldPtr();
	this->renderer = game_object.getRendererPtr();
	this->player = game_object.getPlayerPtr();
}

void GameObserver::setEnemies(std::shared_ptr<std::map<std::pair<size_t, size_t>, enemy_sptr>> enemies)
{
	this->enemies = enemies;
}

std::map<std::pair<size_t, size_t>, enemy_sptr>& GameObserver::getEnemies()
{
	return *this->enemies.lock().get();
}

GameObserver::~GameObserver()
{}

bool GameObserver::handleAction(Action& action)
{
	switch (action.getActionType())
	{
		case ActionType::moveAction:
			return this->handleActionMove(action);
		case ActionType::attackAction:
			return this->handleActionAttack(action);
		case ActionType::deleteItemAction:
			return this->handleActionDeleteItem(action);
		case ActionType::deleteEnemyAction:
			return this->handleActionDeleteEnemy(action);
		case ActionType::pickItemAction:
			return this->handleActionPickItem(action);
		case ActionType::addDrawableAction:
			return this->handleActionAddDrawable(action);
		case ActionType::playerReachEndAction:
			return this->handleActionPlayerReachEnd(action);

		case ActionType::defaultAction:
		default:
			break;
	}
	return false;
}

bool GameObserver::moveLogicForEnemy(ActionMove& action)
{
	if (this->getEnemies().find(action.getCoords()) != this->getEnemies().end())
	{
		return false;
	}
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
	auto entity = this->getEnemies().extract(std::pair<size_t, size_t>{
		action.getEntity().getX(),
		action.getEntity().getY()
	});
	if (!entity.empty())
	{
	    entity.key() = action.getCoords();
	    this->getEnemies().insert(std::move(entity));
	}
	return true;
}

bool GameObserver::moveLogicForPlayer(ActionMove& action)
{
	Cell& target_cell = this->field->getCell(
		action.getCoords().first,
		action.getCoords().second
	);
	if (this->getEnemies().find(action.getCoords()) != this->getEnemies().end())
	{
		ActionAttack act(
			action.getEntity(),
			*this->getEnemies().at(action.getCoords()).get()
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

bool GameObserver::handleActionMove(Action& _action)
{
	ActionMove& action = dynamic_cast<ActionMove&>(_action);
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

	if (this->field->getEnd() == action.getCoords())
	{
		ActionPlayerReachEnd act;
		return this->handleAction(act);
	}
	return true;
}

bool GameObserver::handleActionAttack(Action& _action)
{
	ActionAttack& action = dynamic_cast<ActionAttack&>(_action);
	size_t damage = action.getEntity1().getDamage();
	size_t shield = action.getEntity2().getShield();
	int dhealth = damage - shield;
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
	this->field->getCell(
		action.getItem().getX(),
		action.getItem().getY()
	).setItem(nullptr);
	return true;
}

bool GameObserver::handleActionDeleteEnemy(Action& _action)
{
	ActionDeleteEnemy& action = dynamic_cast<ActionDeleteEnemy&>(_action);
	std::pair<size_t, size_t> coords{
		action.getEnemy().getX(),
		action.getEnemy().getY()
	};
	this->renderer->removeObject(action.getEnemy());
	auto it = this->getEnemies().find(coords);
	if (it == this->getEnemies().end())
		return false;
	(*it).second = nullptr;
	this->getEnemies().erase(it);
	return true;
}

bool GameObserver::handleActionPickItem(Action& _action)
{
	ActionPickItem& action = dynamic_cast<ActionPickItem&>(_action);
	if (!action.getEntity().canPickItem()) 
		return false;
	action.getItem().onPickUp(
		action.getEntity()
	);
	return true;
}

bool GameObserver::handleActionAddDrawable(Action& _action)
{
	ActionAddDrawable& action = dynamic_cast<ActionAddDrawable&>(_action);
	this->renderer.get()->addObject(
		action.getDrawable(),
		60, 60,
		action.getIsBackground()
	);
	return true;
}

bool GameObserver::handleActionPlayerReachEnd(Action& _action)
{
	std::cout << "End reached!" << std::endl;
	return true;
}
