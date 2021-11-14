#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include <functional>
#include <SFML/Graphics.hpp>
#include <memory>

#include "../interfaces/event_handler.h"

class WindowManager
{
public:
	WindowManager(sf::RenderWindow& window);
	bool processEvents();
	void setEventHandler(std::shared_ptr<EventHandler> _handler);
protected:
	sf::RenderWindow& window;
	std::shared_ptr<EventHandler> handler;
};

#endif