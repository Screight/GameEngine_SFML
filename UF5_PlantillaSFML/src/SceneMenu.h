#ifndef SCENE_MENU_H
#define SCENE_MENU_H

#include "Scene.h"

class SceneMenu : public Scene {
public:
		SceneMenu();
		~SceneMenu();

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