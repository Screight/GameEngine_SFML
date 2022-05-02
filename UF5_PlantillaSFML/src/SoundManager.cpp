#include "SoundManager.h"

SoundManager* SoundManager::instance = NULL;

SoundManager* SoundManager::getInstance() {
		if (instance == NULL) {
				instance = new SoundManager();
		}
		return instance;
}

SoundManager::SoundManager() {
		mcurrentSoundIndex = 0;
		mCurrentBGM = NULL;
		mSoundVector.resize(MAX_SOUNDS, NULL);
}

SoundManager::~SoundManager() {

}

void	SoundManager::playMusic(const char* filepath) {
		if (mCurrentBGM != NULL) { musicStop(); }
		mCurrentBGM = new sf::Music();
		if (!mCurrentBGM->openFromFile(filepath)) {
				std::cout << "Error opening music file " << filepath << std::endl;
		}
		mCurrentBGM->play();
		mCurrentBGM->setLoop(true);
}
int		SoundManager::playSound(const char* filepath, bool loop) {
		sf::SoundBuffer* buffer = getBuffer(filepath);
		if (buffer == NULL) { return -1; }
		if (mSoundVector[mcurrentSoundIndex] != NULL) {
				updateSoundFirstFreeSlot();
				if (mcurrentSoundIndex == 0) {
						soundStop(mcurrentSoundIndex);
				}
		}
		int soundID = mcurrentSoundIndex;
		std::cout << "Sound ID: " << soundID << std::endl; //REMOVE ME
		mSoundVector[soundID] = new sf::Sound();
		mSoundVector[soundID]->setBuffer(*buffer);
		mSoundVector[soundID]->play();
		mSoundVector[soundID]->setLoop(loop);
		updateSoundFirstFreeSlot();
		return soundID;
}
void	SoundManager::loadSound(const char* filepath) {
		getBuffer(filepath);
}

void	SoundManager::soundResume(int soundID) {
		if (soundID < 0 || soundID >= MAX_SOUNDS) { return; }
		if (mSoundVector[soundID] == NULL) { return; }
		if (!soundIsPlaying(soundID)) {
				mSoundVector[soundID]->play();
		}
}
void	SoundManager::soundPause(int soundID) {
		if (soundID < 0 || soundID >= MAX_SOUNDS) { return; }
		if (mSoundVector[soundID] == NULL) { return; }
		if (soundIsPlaying(soundID)) {
				mSoundVector[soundID]->pause();
		}
}
void	SoundManager::soundStop(int soundID) {
		if (soundID < 0 || soundID >= MAX_SOUNDS) { return; }
		if (mSoundVector[soundID] == NULL) { return; }

		mSoundVector[soundID]->stop();
		delete(mSoundVector[soundID]);
		mSoundVector[soundID] = NULL;
}
void	SoundManager::soundSetOffset(int soundID, float time) {
		if (soundID < 0 || soundID >= MAX_SOUNDS) { return; }
		if (mSoundVector[soundID] == NULL) { return; }
		mSoundVector[soundID]->setPlayingOffset(sf::seconds(time));
}

void	SoundManager::musicResume() {
		if (mCurrentBGM == NULL) { return; }
		if (!musicIsPlaying()) {
				mCurrentBGM->play();
		}
}
void	SoundManager::musicPause() {
		if (mCurrentBGM == NULL) { return; }
		if (musicIsPlaying()) {
				mCurrentBGM->pause();
		}
}
void	SoundManager::musicStop() {
		if (mCurrentBGM == NULL) { return; }
		mCurrentBGM->stop();
		delete(mCurrentBGM);
		mCurrentBGM = NULL;
}
void	SoundManager::musicSetOffset(float time) {
		if (mCurrentBGM == NULL) { return; }
		mCurrentBGM->setPlayingOffset(sf::seconds(time));
}

bool	SoundManager::musicIsPlaying() {
		if (mCurrentBGM == NULL) { return false; }
		return (mCurrentBGM->getStatus() == sf::Sound::Playing);
}
bool	SoundManager::soundIsPlaying(int soundID) {
		if (soundID < 0 || soundID >= MAX_SOUNDS) { return false; }
		if (mSoundVector[soundID] == NULL) { return false; }
		return (mSoundVector[soundID]->getStatus() == sf::Sound::Playing);
}

sf::SoundBuffer* SoundManager::getBuffer(const char* file) {
		//Si el sonido ha sido cargado previamente, devuelve el buffer
		//Si no, lo carga y devuelve el buffer

		std::map<std::string, sf::SoundBuffer*>::iterator it = mSoundBufferMap.find(file);
		if (it == mSoundBufferMap.end()) //No lo ha encontrado 
		{
				sf::SoundBuffer* buffer = new sf::SoundBuffer();
				bool loaded = buffer->loadFromFile(file);
				if (!loaded) {
						std::cout << "Error opening sound " << file << std::endl;
						return NULL;
				}
				std::cout << "Adding sound " << file << std::endl;
				mSoundBufferMap.insert(std::pair<std::string, sf::SoundBuffer*>(file, buffer));
				it = mSoundBufferMap.find(file);

		}
		return it->second;
}
int SoundManager::updateSoundFirstFreeSlot() {
		mcurrentSoundIndex = 0;
		for (int i = 0; i < MAX_SOUNDS; i++)
		{
				if (mSoundVector[i] == NULL) {
						mcurrentSoundIndex = i;
						break;
				}
				else {
						sf::Time duration = mSoundVector[i]->getBuffer()->getDuration();
						sf::Time offset = mSoundVector[i]->getPlayingOffset();
						if ((offset.asSeconds() >= duration.asSeconds() || offset.asSeconds() == 0) && !soundIsPlaying(i)) {
								soundStop(i);
								mcurrentSoundIndex = i;
								break;
						}
				}
		}

		return mcurrentSoundIndex;
}

void SoundManager::pauseAll() {
		musicPause();
		for (int i = 0; i < MAX_SOUNDS; i++)
		{
				if (!soundIsPlaying(i)) {
						soundPause(i);
				}
		}
}

void SoundManager::resumeAll() {
		musicResume();
		for (int i = 0; i < MAX_SOUNDS; i++)
		{
				soundResume(i);
		}
}