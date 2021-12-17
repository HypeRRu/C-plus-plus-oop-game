#ifndef BASE_BUTTON_H
#define BASE_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <map>

#include "texture_manager.h"

class BaseWindow;

class BaseButton: public sf::Drawable
{
public:
	BaseButton(
		BaseWindow& _holder,
		const std::string& _text,
		std::pair<int, int> _size = {60, 20},
		std::pair<int, int> _position = {0, 0},
		std::string clickMsg = ""
	);
	void setSize(std::pair<int, int> _size = {60, 20});
	void setPosition(std::pair<int, int> _position = {0, 0});
	void setText(const std::string& _text = "");
	void setOnClick(const std::string& _onClick = "");
	void setIsActive(bool state = false);
	bool getIsActive() const;

	virtual void click() const;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	void configureSprite();

	std::pair<int, int> position;
	std::pair<int, int> size;

	std::string text;
	std::string onClick;
	bool is_active;

	BaseWindow& holder;
	sf::RectangleShape button;
	sf::Font font;
	sf::Text label;
};

#endif