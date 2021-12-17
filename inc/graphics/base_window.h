#ifndef BASE_WINDOW_H
#define BASE_WINDOW_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <functional>
#include <map>

#include "base_button.h"

class BaseWindow: public sf::Drawable
{
public:
	BaseWindow(
		std::pair<int, int> _size,
		std::pair<int, int> _position = {0, 0}
	);

	virtual void addButton(
		const std::string& btn_text,
		std::function<void(BaseWindow&)> onClick,
		const std::string action_msg = ""
	);
	void nextButton();
	void previousButton();
	void clickButton();

	void resize(std::pair<int, int> _size);
	void setPosition(std::pair<int, int> _position);

	virtual void notify(const std::string& message);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
protected:
	virtual void configureWindow();

	std::vector<std::unique_ptr<BaseButton>> buttons;
	int current_button;
	double button_rel_height;
	int offset_px;

	std::pair<int, int> size;
	std::pair<int, int> position;
	sf::RectangleShape window;
	sf::RectangleShape shadow;

	std::map<
		std::string,
		std::function<void(BaseWindow&)>
	> actions;
};

#endif