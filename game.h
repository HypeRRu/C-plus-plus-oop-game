#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <memory>
#include <vector>
#include <ctime>
#include <chrono>
#include <thread>

#include "utils/field_generator.h"
#include "field.h"

#include "graphics/renderer.h"

class Game
{
public:
	Game();
	~Game() = default;

	bool run();
	bool fillField();

	Renderer& getRenderer() const;
private:
	std::unique_ptr<Renderer> renderer;
	std::unique_ptr<Field> field;
	FieldGenerator generator;
};

#endif