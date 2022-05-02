#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include "includes.h"

#define MAX_SOUNDS 40
//PROXY AUDIO
//SINGLETON

//!SoundManager class
//! Handles the loading and management of the Sounds in the game

class SoundManager {
public:
		static SoundManager* getInstance();
		~SoundManager();

		void	playMusic(const char* filepath);
		int		playSound(const char* filepath, bool loop = false);
		void	loadSound(const char* filepath);

		void	soundResume(int soundID);
		void	soundPause(int soundID);
		void	soundStop(int soundID);
		void	soundSetOffset(int soundID, float time);

		void	musicResume();
		void	musicPause();
		void	musicStop();
		void	musicSetOffset(float time);

		bool	musicIsPlaying();
		bool	soundIsPlaying(int ID);

		void	resumeAll();
		void	pauseAll();

private:
		SoundManager();
		static SoundManager* instance;

		sf::SoundBuffer* getBuffer(const char* file);
		int updateSoundFirstFreeSlot();

		std::map<std::string, sf::SoundBuffer*> mSoundBufferMap;
		std::vector<sf::Sound*>					mSoundVector; //effect sounds
		sf::Music* mCurrentBGM; //background music

		int mcurrentSoundIndex;
};
#endif
