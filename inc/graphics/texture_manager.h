#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <stdexcept>

class TextureManager
{
public:
	static TextureManager& instance();

	TextureManager(const TextureManager&) = delete;
	TextureManager& operator =(const TextureManager&) = delete;

	const sf::Texture& get(const std::string& alias, const std::string& path = "");
	bool addTexture(const std::string& alias, const std::string& path);
private:
	TextureManager() = default;
	std::map<std::string, sf::Texture> textures;
};

#endif