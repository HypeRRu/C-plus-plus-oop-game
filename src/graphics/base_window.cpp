#include "../../inc/graphics/base_window.h"

BaseWindow::BaseWindow(
	std::pair<int, int> _size,
	std::pair<int, int> _position
): current_button{0}, button_rel_height{10.f}, offset_px{6}
{
	this->resize(_size);
	this->setPosition(_position);
	this->configureWindow();
}

void BaseWindow::addButton(
	const std::string& btn_text,
	std::function<void(BaseWindow&)> onClick,
	const std::string action_msg
)
{
	std::string msg;
	this->buttons.push_back(
		std::make_unique<BaseButton>(
			*this,
			btn_text,
			std::pair<int, int>({0, 0}),
			std::pair<int, int>({0, 0})
		)
	);
	this->configureWindow();
	if (this->buttons.size() == 1)
		this->buttons.at(0)->setIsActive(true);
	// add action handler
	if (action_msg == "")
		msg = btn_text;
	else
		msg = action_msg;
	this->buttons.back()->setOnClick(msg);
	this->actions.insert_or_assign(
		msg,
		onClick
	);
}

void BaseWindow::nextButton()
{
	if (!this->buttons.size())
		return;
	this->buttons.at(this->current_button++)->setIsActive(false);
	this->current_button %= this->buttons.size();
	this->buttons.at(this->current_button)->setIsActive(true);
}

void BaseWindow::previousButton()
{
	if (!this->buttons.size())
		return;
	this->buttons.at(this->current_button--)->setIsActive(false);
	this->current_button = 
		(this->current_button + this->buttons.size()) % this->buttons.size();
	this->buttons.at(this->current_button)->setIsActive(true);
}

void BaseWindow::clickButton()
{
	if (!this->buttons.size())
		return;
	this->buttons.at(this->current_button)->click();
}

void BaseWindow::resize(std::pair<int, int> _size)
{
	this->size = _size;
	this->configureWindow();
}

void BaseWindow::setPosition(std::pair<int, int> _position)
{
	this->position = _position;
	this->configureWindow();
}

void BaseWindow::notify(const std::string& message)
{
	if (this->actions.find(message) != this->actions.end())
		this->actions[message](*this);
}

void BaseWindow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->shadow, states);
	target.draw(this->window, states);
	for (auto& btn: this->buttons)
		btn->draw(target, states);
}

void BaseWindow::configureWindow()
{
	double size_x, size_y;
	double pos_x, pos_y;
	double y_offset;
	// buttons
	size_x = this->size.first / 1.5f;
	size_y = this->size.second / this->button_rel_height;
	pos_x = this->position.first + this->size.first / 6.0f;
	y_offset = this->size.second / 2.f;
	y_offset -= this->size.second / (this->button_rel_height * 2) * this->buttons.size();
	for (int i = 0; i < this->buttons.size(); ++i)
	{
		pos_y = this->position.second + y_offset + i * this->size.second / 10.0f + offset_px * i;
		this->buttons.at(i)->setSize({size_x, size_y});
		this->buttons.at(i)->setPosition({pos_x, pos_y});
	}
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
