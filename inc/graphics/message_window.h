#ifndef MESSAGE_WINDOW_H
#define MESSAGE_WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "base_window.h"

class MessageWindow: public BaseWindow
{
public:
	MessageWindow(
		const std::string& _message = ""
	);

	virtual void setText(const std::string& text);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	void configureWindow();
	
	std::string message;
	sf::Font font;
	sf::Text label;
};

#endif