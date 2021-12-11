#include "../../inc/graphics/base_button.h"
#include "../../inc/graphics/base_window.h"

BaseButton::BaseButton(
	BaseWindow& _holder,
	const std::string& _text,
	std::pair<int, int> _size,
	std::pair<int, int> _position,
	std::string clickMsg
): holder{_holder}
{
	this->font.loadFromFile("assets/fonts/pricedown.otf");
	this->setPosition(_position);
	this->setSize(_size);
	this->setText(_text);
	this->setIsActive(false);
	this->setOnClick(clickMsg);
	this->configureSprite();
}

void BaseButton::setSize(std::pair<int, int> _size)
{
	this->size = _size;
	this->configureSprite();
}

void BaseButton::setPosition(std::pair<int, int> _position)
{
	this->position = _position;
	this->configureSprite();
}

void BaseButton::setText(const std::string& _text)
{
	this->text = _text;
	// change label
	this->label.setString(this->text);
}

void BaseButton::setOnClick(const std::string& _onClick)
{
	this->onClick = _onClick;
}

void BaseButton::setIsActive(bool state)
{
	this->is_active = state;
	// change color
	if (this->is_active)
		this->label.setColor(sf::Color(0, 100, 255, 150)); // active color
	else
		this->label.setColor(sf::Color(105, 105, 105, 250)); // normal color
}

bool BaseButton::getIsActive() const
{
	return this->is_active;
}

void BaseButton::click() const
{
	this->holder.notify(this->onClick);
}

void BaseButton::draw(sf::RenderTarget& target,sf::RenderStates states) const
{
	target.draw(this->button, states);
	target.draw(this->label, states);
}

void BaseButton::configureSprite()
{
	this->label.setString(this->text);
	if (this->is_active)
		this->label.setColor(sf::Color(0, 100, 255, 150)); // active color
	else
		this->label.setColor(sf::Color(105, 105, 105, 250)); // normal color
	this->label.setFont(font);

	this->button.setSize(
		sf::Vector2f(
			this->size.first, 
			this->size.second
		)
	);
	this->button.setPosition(
		sf::Vector2f(
			this->position.first, 
			this->position.second
		)
	);
	this->button.setFillColor(sf::Color(230, 230, 250, 170)); // normal color
	this->button.setOutlineThickness(2);
	this->button.setOutlineColor(sf::Color(255, 255, 255, 100));

	int label_x, label_y;
	label_x = this->position.first + (this->size.first - this->label.getLocalBounds().width) / 2.f;
	label_y = this->position.second + (this->size.second - this->label.getLocalBounds().height) / 4.f;
	this->label.setPosition(
		sf::Vector2f(
			label_x, 
			label_y
		)
	);
}
