#include "../../inc/graphics/save_window.h"

SaveWindow::SaveWindow(StateSave& state):
	BaseWindow(
		{400, 400},
		{400, 250}
	), state{state}
{
	this->addButton(
		"Slot 1",
		[&](BaseWindow& window)->void {
			this->state.saveInSlot(1);
		},
		"slot_1"
	);
	this->addButton(
		"Slot 2",
		[&](BaseWindow& window)->void {
			this->state.saveInSlot(2);
		},
		"slot_2"
	);
	this->addButton(
		"Slot 3",
		[&](BaseWindow& window)->void {
			this->state.saveInSlot(3);
		},
		"slot_3"
	);
	this->addButton(
		"Back",
		[&](BaseWindow& window)->void {
			this->state.back();
		},
		"back"
	);
}
