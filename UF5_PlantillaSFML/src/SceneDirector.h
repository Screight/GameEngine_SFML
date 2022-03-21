#ifndef SCENE_DIRECTOR_H
#define SCENE_DIRECTOR_H

#include "includes.h"
#include "Scene.h"

class SceneDirector {
public:
		enum SceneEnum { MAINMENU, GAME, LAST_NO_USE};

		static SceneDirector* GetInstance();
		~SceneDirector() {};

		void ChangeScene(SceneEnum p_nextScene, bool p_loadOnReturn, bool p_addToHistory);
		void GoToLastScene(bool p_loadOnReturn);

		Scene* GetCurrentScene() { return m_currentScene; };

private:
		SceneDirector();
		void PreLoadScenes();
		static SceneDirector* m_instance;
		Scene* m_currentScene;

		std::vector<Scene*> m_scenes;
		std::stack<Scene*> m_sceneHistory;
};

#endif // !SCENE_DIRECTOR_H
