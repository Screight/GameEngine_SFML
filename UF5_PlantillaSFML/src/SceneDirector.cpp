#include "SceneDirector.h"
#include "SceneMenu.h"
#include "SceneGame.h"

SceneDirector* SceneDirector::m_instance = NULL;

SceneDirector::SceneDirector() {
		PreLoadScenes();
}

SceneDirector* SceneDirector::GetInstance()
{
		if (m_instance == NULL) { m_instance = new SceneDirector(); }
		return m_instance;
}

void SceneDirector::ChangeScene(SceneEnum p_nextScene, bool p_loadOnReturn, bool p_addToHistory)
{
		m_currentScene->SetIsSceneLoaded(!p_loadOnReturn);
		if (p_addToHistory) { m_sceneHistory.push(m_currentScene); }
		m_currentScene = m_scenes[p_nextScene];
}

void SceneDirector::GoToLastScene(bool p_loadOnReturn)
{
		if (m_sceneHistory.empty()) { return; }
		Scene* scene = m_sceneHistory.top();
		if (scene != NULL) { m_sceneHistory.pop(); }
		m_currentScene->SetIsSceneLoaded(p_loadOnReturn);
		m_currentScene = scene;
}

void SceneDirector::PreLoadScenes()
{
		m_scenes.resize(SceneDirector::SceneEnum::LAST_NO_USE);

		SceneMenu* sceneMenu = new SceneMenu();
		SceneGame* sceneGame =  new SceneGame();

		m_scenes[MAINMENU] = sceneMenu;
		m_scenes[GAME] = sceneGame;

		for (int i = 0; i < SceneDirector::LAST_NO_USE; i++) {
				m_scenes[i]->PreLoad();

				m_currentScene = m_scenes[MAINMENU];
		}

}
