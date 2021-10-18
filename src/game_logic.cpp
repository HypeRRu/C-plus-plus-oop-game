#include "../inc/game_logic.h"

std::pair<int, int> GameLogic::processWindowEventsAndGetMovement(sf::RenderWindow& window)
{
	std::pair<int, int> movement{0, 0};
	sf::Event event;
	while (window.pollEvent(event))
	{
	    switch (event.type)
	    {
	        case sf::Event::Closed:
	            window.close();
	            break;
	        case sf::Event::KeyPressed:
	            if (event.key.code 		== sf::Keyboard::Left)
					movement.first--;
				else if (event.key.code == sf::Keyboard::Right)
					movement.first++;
				else if (event.key.code == sf::Keyboard::Up)
					movement.second--;
				else if (event.key.code == sf::Keyboard::Down)
					movement.second++;
	            break;
	        default:
	            break;
	    }
	    if (movement.first > 1)
	    	movement.first = 1;
	    if (movement.second > 1)
	    	movement.second = 1;
	    if (movement.first < -1)
	    	movement.first = -1;
	    if (movement.second < -1)
	    	movement.second = -1;
	}
	return movement;
}
