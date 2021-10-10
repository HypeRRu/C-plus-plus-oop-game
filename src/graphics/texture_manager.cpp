#include "../../inc/graphics/texture_manager.h"

TextureManager& TextureManager::instance()
{
	static TextureManager manager;
	return manager;
}

const sf::Texture& TextureManager::get(const std::string& alias, const std::string& path)
{
	if (textures.find(alias) == textures.end())
		addTexture(alias, path);
	return textures.at(alias);
}

bool TextureManager::addTexture(const std::string& alias, const std::string& path)
{
	if (textures[alias].loadFromFile(path))
		return false;
	return true;
}	
