#pragma once
#include <SFML\Graphics.hpp>
#include <map> // To store textures and fonts

namespace Breakout {

	class AssetManager
	{
	public:
		AssetManager() {}
		~AssetManager() {}

		void LoadTexture(std::string name, std::string fileName);
		sf::Texture &GetTexture(std::string name); //alows to get a particular texture

		void LoadFont(std::string name, std::string fileName);
		sf::Font &GetFont(std::string name); //alows to get a particular texture
	
	private:
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;
	};
}

