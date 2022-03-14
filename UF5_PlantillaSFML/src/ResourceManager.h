#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include "includes.h"
#include <vector>
#include <map>
#include <iterator>
#include <SFML/Graphics.hpp>

// PROXY SPRITE CLASS
// IS A SINGLETON

//! Handles the loading and magagement of the Textures in the game
class ResourceManager {
public:
		static ResourceManager* GetInstance();

		int							GetSpriteID(const char* p_filePath);
		sf::Sprite*			GetSpriteByID(int p_id);
		unsigned int		GetSpriteWidth(int p_ide);
		unsigned int		GetSpriteHeight(int p_ide);


private:
		ResourceManager();
		~ResourceManager();
		
		static ResourceManager*							p_instance;
		int							SearchSprite(sf::Sprite* p_sprite);
		int							GetTextureID(const char* p_filePath);
		int							AddTexture(const char* p_filePath);
		sf::Texture*			GetTextureByID(int p_id);

		// TO DO: Texture free functions

		int UpdateFirstFreeSlot();

		std::map<std::string, sf::Sprite*>	m_spritesMap;
		std::vector<sf::Sprite*>						m_spritesVector;
		std::map<std::string, sf::Texture*>	m_textureMap;
		std::vector<sf::Texture*>						m_textureVector;
		std::map<std::string, int>					m_idMap;

		int																	m_firstFreeSlot;

};

#endif // !RESOURCE_MANAGER
