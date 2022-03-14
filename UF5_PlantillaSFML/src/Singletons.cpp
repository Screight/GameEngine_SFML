#include "Singletons.h"

Renderer* g_renderer = NULL;
ResourceManager* g_resourceManager = NULL;

void InitializeSingetons() {
		g_renderer = Renderer::GetInstance();
		g_resourceManager = ResourceManager::GetInstance();
}