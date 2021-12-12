#include "../../inc/graphics/pause_window.h"

PauseWindow::PauseWindow(StatePause& state):
	BaseWindow(
		{400, 400},
		{400, 250}
	), state{state}
{
	this->addButton(
		"Play",
		[&](BaseWindow& window)->void {
			this->state.play();
		},
		"play"
	);
	this->addButton(
		"Save",
		[&](BaseWindow& window)->void {
			this->state.saveGame();
		},
		"save"
	);
	this->addButton(
		"Load",
		[&](BaseWindow& window)->void {
			this->state.loadGame();
		},
		"load"
	);
	this->addButton(
		"To Main Menu",
		[&](BaseWindow& window)->void {
			this->state.toMenu();
		},
		"toMenu"
	);
	this->addButton(
		"Exit",
		[&](BaseWindow& window)->void {
			this->state.exit();
		},
		"exit"
	);
}
