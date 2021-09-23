#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>

#include "texture_manager.h"

class Renderer
{
public:
	Renderer(size_t w_width = 0, size_t w_height = 0, std::string title = "");
	~Renderer();

	Renderer(const Renderer& other);
	Renderer(Renderer&& other);

	Renderer& operator =(const Renderer& other);
	Renderer& operator =(Renderer&& other);

	sf::RenderWindow& getWindow();

	bool renderFrame();
	bool isWindowOpen();

	void addObject(
		size_t x, 
		size_t y, 
		size_t object_w, 
		size_t object_h, 
		const std::string& texture_alias,
		bool is_static = false
	);

	void flushObjects(bool flush_static = false);

	// void modifyObject()
private:
	sf::RenderWindow window;
	size_t w_width, w_height;
	std::string title;
	std::vector<sf::Sprite> static_render_objects;
	std::vector<sf::Sprite> render_objects;
};

#endif