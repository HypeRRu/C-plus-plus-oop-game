#include "../../inc/graphics/message_window.h"

MessageWindow::MessageWindow(
	const std::string& _message
):	BaseWindow(
		{500, 400},
		{350, 250}
	), message{_message}
{
	this->font.loadFromFile("assets/fonts/etna.otf");
	this->configureWindow();
}

void MessageWindow::setText(const std::string& text)
{
	this->message = text;
	this->configureWindow();
}

void MessageWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shadow, states);
	target.draw(this->window, states);
	target.draw(this->label, states);
}

void MessageWindow::configureWindow()
{	
	// label
	this->label.setString(this->message);
	this->label.setColor(sf::Color(225, 225, 225, 250)); // normal color
	this->label.setFont(font);
	int label_x, label_y;
	label_x = this->position.first + (this->size.first - this->label.getLocalBounds().width) / 2.f;
	label_y = this->position.second + (this->size.second - this->label.getLocalBounds().height) / 4.f;
	this->label.setPosition(
		sf::Vector2f(
			label_x, 
			label_y
		)
	);
	// window shape
	this->window.setSize(
		sf::Vector2f(
			this->size.first, 
			this->size.second
		)
	);
	this->window.setPosition(
		sf::Vector2f(
			this->position.first, 
			this->position.second
		)
	);
	this->window.setFillColor(sf::Color(112, 128, 144, 100));
	// window shadow
	this->shadow.setSize(
		sf::Vector2f(
			this->size.first, 
			this->size.second
		)
	);
	this->shadow.setPosition(
		sf::Vector2f(
			this->position.first + 5, 
			this->position.second - 5
		)
	);
	this->shadow.setFillColor(sf::Color(10, 10, 10, 50));
}
