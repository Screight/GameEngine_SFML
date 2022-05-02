#ifndef SCENE_GAME_H
#define SCENE_GAME_H

#include "Scene.h"
#include "Entity.h"

class SceneGame : public Scene {
public:
		SceneGame();
		~SceneGame();

		virtual void PreLoad();

protected:
		virtual void Initialize();

		virtual void EarlyUpdate();
		virtual void Update();
		virtual void LateUpdate();

		virtual void EarlyRender();
		virtual void Render();
		virtual void LateRender();

		virtual void RenderGUI();

		virtual void loadMap();
		virtual void renderMap();

		Entity* m_player;
		int mpMapWidth = 0;
		int mpMapHeight = 0;
		std::vector<std::vector<bool>> mpCollisionMap;
		int mwallImg;

};

#endif // !SCENE_MENU_H