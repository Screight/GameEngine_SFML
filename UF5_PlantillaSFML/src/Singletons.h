#ifndef SINGLETONS_H
#define SINGLETONS_H

#include "Renderer.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneDirector.h"

void InitializeSingletons();

extern Renderer*				g_renderer;
extern ResourceManager*	g_resourceManager;
extern InputManager*		g_inputManager;
extern SceneDirector* g_sceneDirector;

#endif