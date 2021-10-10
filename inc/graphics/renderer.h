#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include <functional>
#include <map>

#include "texture_manager.h"
#include "../actions/base_observed.h"
#include "../interfaces/drawable.h"

class Renderer: public BaseObserved
{
public:
	Renderer(size_t w_width = 0, size_t w_height = 0, std::string title = "");
	~Renderer();

	sf::RenderWindow& getWindow();

	bool renderFrame();
	bool isWindowOpen();

	void addObject(
		const Drawable& object,
		size_t object_w,
		size_t object_h,
		bool bg_object = true
	);

	bool removeObject(const Drawable& object);
	void flushObjects();
private:
	sf::RenderWindow window;
	size_t w_width, w_height;
	std::string title;
	std::map<size_t, sf::Sprite> render_objects_bg; /* background objects */
	std::map<size_t, sf::Sprite> render_objects_fg; /* foreground objects */
};

#endif