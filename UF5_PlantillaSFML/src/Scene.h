#ifndef SCENE_H
#define SCENE_H

#include "includes.h"

class Scene {
public:
		Scene();
		~Scene();

		virtual void		PreLoad();
		void						OnLoad();
		void						OnUpdate();
		void						OnRender();
		
		void SetIsSceneLoaded(bool p_isSceneLoaded) { m_isSceneLoaded = p_isSceneLoaded; }

protected:
		bool m_isSceneLoaded;

		virtual void Initialize(); 

		virtual void EarlyUpdate();
		virtual void Update();
		virtual void LateUpdate();

		virtual void EarlyRender();
		virtual void Render();
		virtual void LateRender();

		virtual void RenderGUI();
};


#endif // !SCENE_H
