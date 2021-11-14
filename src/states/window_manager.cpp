#include "../../inc/states/window_manager.h"

WindowManager::WindowManager(sf::RenderWindow& window): window{window}
{}

void WindowManager::setEventHandler(std::shared_ptr<EventHandler> _handler)
{
	this->handler = _handler;
}

bool WindowManager::processEvents()
{
	std::map<sf::Keyboard::Key, Event> controls = GameConfig::instance().getControls();
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			return this->handler->handleEvent(Event::EventGameClosed);
		if (event.type != sf::Event::KeyPressed)
			continue;
		
		if (controls.find(event.key.code) != controls.end())
			this->handler->handleEvent(controls.at(event.key.code));
	}
	return true;
}
