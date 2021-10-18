#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SFML/Graphics.hpp>
#include <memory>

class GameLogic
{
public:
	GameLogic() = default;

	std::pair<int, int> processWindowEventsAndGetMovement(sf::RenderWindow& window);
};

#endif
