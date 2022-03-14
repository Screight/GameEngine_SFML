#ifndef SINGLETONS_H
#define SINGLETONS_H

#include "Renderer.h"
#include "ResourceManager.h"

void InitializeSingetons();

extern Renderer*				g_renderer;
extern ResourceManager*	g_resourceManager;

#endif