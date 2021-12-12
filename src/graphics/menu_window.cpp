#include "../../inc/graphics/menu_window.h"

MenuWindow::MenuWindow(StateMenu& state):
	BaseWindow(
		{400, 400},
		{400, 250}
	), state{state}
{
	this->addButton(
		"Play",
		[&](BaseWindow& window)->void {
			this->state.start();
		},
		"start"
	);
	this->addButton(
		"Load",
		[&](BaseWindow& window)->void {
			this->state.loadGame();
		},
		"load"
	);
	this->addButton(
		"Exit",
		[&](BaseWindow& window)->void {
			this->state.exit();
		},
		"exit"
	);
}
