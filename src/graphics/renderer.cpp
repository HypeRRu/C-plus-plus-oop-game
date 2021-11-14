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
	TextureManager::instance().addTexture("coin_item", "assets/textures/coin.png");
	TextureManager::instance().addTexture("enemy_regular", "assets/textures/enemy_regular.png");
	TextureManager::instance().addTexture("enemy_daemon", "assets/textures/enemy_daemon.png");
	TextureManager::instance().addTexture("enemy_gargoyle", "assets/textures/gargoyle.png");

	size_t base_layers_cnt = 5;
	this->render_objects.resize(base_layers_cnt);
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

	/* render all layers */
	for (slayer& layer: this->render_objects)
	{
		for (std::pair<size_t, sf::Sprite> object: layer)
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
	size_t layer
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

	if (this->render_objects.size() <= layer)
		this->render_objects.resize(layer + 1);
	this->render_objects.at(layer).insert_or_assign(hash, sprite);
}

bool Renderer::removeObject(const Drawable& object)
{
	std::hash<const Drawable*> obj_hash;
	size_t hash = obj_hash(&object);

	for (slayer& layer: this->render_objects)
	{
		if (layer.find(hash) != layer.end())
		{
			layer.erase(hash);
			return true;
		}
	}
	return false;
}

void Renderer::flushObjects()
{
	for (slayer& layer: this->render_objects)
		layer.clear();
}
