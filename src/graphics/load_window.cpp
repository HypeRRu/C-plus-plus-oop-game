#include "../../inc/graphics/load_window.h"

LoadWindow::LoadWindow(StateLoad& state):
	BaseWindow(
		{400, 400},
		{400, 250}
	), state{state}
{
	this->addButton(
		"Slot 1",
		[&](BaseWindow& window)->void {
			this->state.loadFromSlot(1);
		},
		"slot_1"
	);
	this->addButton(
		"Slot 2",
		[&](BaseWindow& window)->void {
			this->state.loadFromSlot(2);
		},
		"slot_2"
	);
	this->addButton(
		"Slot 3",
		[&](BaseWindow& window)->void {
			this->state.loadFromSlot(3);
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
