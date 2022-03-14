#include "ResourceManager.h"

ResourceManager* ResourceManager::p_instance = NULL;

ResourceManager::ResourceManager():
				m_firstFreeSlot(0)
		{}

ResourceManager::~ResourceManager() {

}

ResourceManager* ResourceManager::GetInstance() {
		if (p_instance == NULL) {
				p_instance = new ResourceManager();
		}
		return p_instance;
}

int ResourceManager::GetSpriteID(const char* p_filePath) {
		int textureID = GetTextureID(p_filePath);
		if (textureID != -1) {
				std::map<std::string, sf::Sprite*>::iterator iterator = m_spritesMap.find(p_filePath);
				if (iterator == m_spritesMap.end()) {
						sf::Sprite* sprite = new sf::Sprite();
						sprite->setTexture(*GetTextureByID(textureID));
						m_spritesMap.insert(std::pair<std::string, sf::Sprite*>(p_filePath, sprite));
						int returnValue = 0;
						m_spritesVector.push_back(sprite); // put sprite in first free slot of the vector
						returnValue = m_spritesVector.size() - 1; // updateFirstFreeSlot
						return returnValue;
				}
				else {
						return SearchSprite(iterator->second);
				}
		}
};

sf::Sprite* ResourceManager::GetSpriteByID(int p_id) {
		if (p_id >= 0 && m_spritesVector.size()) { return m_spritesVector[p_id]; }
		else { return NULL; }
};

unsigned int ResourceManager::GetSpriteWidth(int p_id) {
		sf::Sprite* sprite = GetSpriteByID(p_id);
		if (sprite == NULL) { return - 1; }
		return sprite->getTexture()->getSize().x;
};

unsigned int ResourceManager::GetSpriteHeight(int p_id) {
		sf::Sprite* sprite = GetSpriteByID(p_id);
		if (sprite == NULL) { return -1; }
		return sprite->getTexture()->getSize().y;
};

int ResourceManager::SearchSprite(sf::Sprite* p_sprite) {
		int size = m_spritesVector.size();
		for (int i = 0; i < size; i++) {
				if (m_spritesVector[i] == p_sprite) { return i; }
		}
		return -1;
};

int ResourceManager::GetTextureID(const char* p_filePath) {
		std::map<std::string, sf::Texture*>::iterator iterator = m_textureMap.find(p_filePath);
		int returnValue = -1;
		if (iterator == m_textureMap.end()) {
				std::cout << "Adding Texture " << p_filePath << std::endl;
				int index = AddTexture(p_filePath);
				m_idMap.insert(std::pair<std::string, int>(p_filePath, index));
				returnValue = index;
		}
		else {
				std::map <std::string, int>::iterator iterator = m_idMap.find(p_filePath);
				if (iterator == m_idMap.end()) {
						std::cout << "Failed to find " << p_filePath << " ont the map." << std::endl;
						returnValue = -1;
				}
				else { return iterator->second; }
		}
};
int ResourceManager::AddTexture(const char* p_filePath) {
		sf::Texture* texture = new sf::Texture();
		bool loaded = texture->loadFromFile(p_filePath);
		
		if (!loaded) {
				std::cerr << "Error when loading image: " << p_filePath << std::endl;
		}
		else {
				m_textureMap.insert(std::pair<std::string, sf::Texture*>(p_filePath, texture));
				int returnValue = 0;
				if (m_firstFreeSlot == m_textureVector.size()) {
						m_textureVector.push_back(texture);
						m_firstFreeSlot++;
						returnValue = m_textureVector.size() - 1;
				}
				else {
						m_textureVector[m_firstFreeSlot] = texture;
						returnValue = m_firstFreeSlot;
						m_firstFreeSlot = UpdateFirstFreeSlot();
				}
				return returnValue;
		}

		return -1;
};
sf::Texture* ResourceManager::GetTextureByID(int p_id) {
		if (p_id >= 0 && m_spritesVector.size()) { return m_textureVector[p_id]; }
		else { return NULL; }
};
int ResourceManager::UpdateFirstFreeSlot() {
		int size = m_textureVector.size();
		for (int i = 0; i < size; i++) {
				if (m_textureVector[i] == NULL) {
						return i;
				}
		}
		return m_textureVector.size();
};