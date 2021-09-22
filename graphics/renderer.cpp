#include "renderer.h"

Renderer::Renderer(size_t w_width, size_t w_height, std::string title):
	w_width{w_width}, w_height{w_height}, title{title}
{
	this->window.create(
		sf::VideoMode(w_width, w_height), 
		title
	);

	TextureManager::instance().addTexture("cell_regular", "assets/textures/cell_regular.png");
	TextureManager::instance().addTexture("cell_start", "assets/textures/cell_start.png");
	TextureManager::instance().addTexture("cell_end", "assets/textures/cell_end.png");
	TextureManager::instance().addTexture("cell_wall", "assets/textures/cell_wall.png");

	static_render_objects.resize(w_width * w_height);
}

Renderer::~Renderer()
{
	this->getWindow().close();
}

bool Renderer::renderFrame()
{
	if (!this->isWindowOpen())
		return false;

	this->getWindow().clear(sf::Color(255, 255, 255, 0));

	for (auto& object: this->static_render_objects)
	{
		this->getWindow().draw(object);
	}
	for (auto& object: this->render_objects)
	{
		this->getWindow().draw(object);
	}

	sf::Event event;
	while (this->getWindow().pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->getWindow().close();
			return false;
		}
	}
	
	this->getWindow().display();

	return true;
}

bool Renderer::isWindowOpen()
{
	return this->getWindow().isOpen();
}

sf::RenderWindow& Renderer::getWindow()
{
	return this->window;
}

Renderer::Renderer(const Renderer& other): 
	w_width{other.w_width}, w_height{other.w_height}, title{other.title}
{
	this->window.create(
		sf::VideoMode(w_width, w_height), 
		title
	);
}

Renderer::Renderer(Renderer&& other):
	w_width{other.w_width}, w_height{other.w_height}, title{other.title}
{
	this->window.create(
		sf::VideoMode(other.w_width, other.w_height), 
		other.title
	);
}

Renderer& Renderer::operator =(const Renderer& other)
{
	if (&other == this)
		return *this;

	this->w_width = other.w_width;
	this->w_height = other.w_height;
	this->title = other.title;
	this->window.create(
		sf::VideoMode(w_width, w_height), 
		title
	);

	return *this;
}

Renderer& Renderer::operator =(Renderer&& other)
{
	if (&other == this)
		return *this;

	std::swap(this->w_height, other.w_height);
	std::swap(this->w_width, other.w_width);
	std::swap(this->title, other.title);
	this->window.create(
		sf::VideoMode(w_width, w_height), 
		title
	);

	return *this;
}

void Renderer::addObject(
		size_t x, 
		size_t y, 
		size_t object_w, 
		size_t object_h, 
		const std::string& texture_name,
		bool is_static
	)
{
	sf::Texture texture = TextureManager::instance().get(texture_name);
	sf::Sprite object;
	object.setPosition(
		x * object_w, 
		y * object_h
	);
	object.setTexture(TextureManager::instance().get(texture_name));
	object.setScale(
		object_w / static_cast<float>(texture.getSize().x),
		object_h / static_cast<float>(texture.getSize().y)
	);

	if (is_static)
		static_render_objects.push_back(object);
	else
		render_objects.push_back(object);
}

void Renderer::flushObjects(bool flush_static)
{
	render_objects.clear();
	if (flush_static)
		static_render_objects.clear();
}
