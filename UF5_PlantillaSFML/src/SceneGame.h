#ifndef SCENE_GAME_H
#define SCENE_GAME_H

#include "Scene.h"

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

};

#endif // !SCENE_MENU_H