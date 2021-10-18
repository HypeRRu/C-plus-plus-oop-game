#include "../../inc/graphics/renderer.h"

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
	TextureManager::instance().addTexture("player", "assets/textures/player.png");
	TextureManager::instance().addTexture("heal_item", "assets/textures/heal.png");
	TextureManager::instance().addTexture("shield_item", "assets/textures/armor.png");
	TextureManager::instance().addTexture("weapon_item", "assets/textures/knife.png");
	TextureManager::instance().addTexture("enemy_regular", "assets/textures/enemy_regular.png");
	TextureManager::instance().addTexture("enemy_daemon", "assets/textures/enemy_daemon.png");
	TextureManager::instance().addTexture("enemy_gargoyle", "assets/textures/gargoyle.png");
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

	/* render background objects first */
	for (std::pair<size_t, sf::Sprite> object: this->render_objects_bg)
	{
		this->getWindow().draw(object.second);
	}
	/* render foreground objects */
	for (std::pair<size_t, sf::Sprite> object: this->render_objects_fg)
	{
		this->getWindow().draw(object.second);
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

void Renderer::addObject(
	const Drawable& object,
	size_t object_w,
	size_t object_h,
	bool bg_object
)
{
	const sf::Texture& texture = TextureManager::instance().get(object.getView().getTextureAlias());
	sf::Sprite sprite;

	sprite.setPosition(
		object.getX() * object_w,
		object.getY() * object_h
	);
	sprite.setTexture(texture);
	sprite.setScale(
		object_w / static_cast<float>(texture.getSize().x),
		object_h / static_cast<float>(texture.getSize().y)
	);

	std::hash<const Drawable*> obj_hash;
	size_t hash = obj_hash(&object);

	if (bg_object)
		render_objects_bg.insert_or_assign(hash, sprite);
	else
		render_objects_fg.insert_or_assign(hash, sprite);
}

bool Renderer::removeObject(const Drawable& object)
{
	std::hash<const Drawable*> obj_hash;
	size_t hash = obj_hash(&object);

	if (render_objects_bg.find(hash) != render_objects_bg.end())
	{
		render_objects_bg.erase(hash);
		return true;
	}
	if (render_objects_fg.find(hash) != render_objects_fg.end())
	{
		render_objects_fg.erase(hash);
		return true;
	}
	return false;
}

void Renderer::flushObjects()
{
	render_objects_bg.clear();
	render_objects_fg.clear();
}
