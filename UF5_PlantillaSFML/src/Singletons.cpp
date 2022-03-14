#include "Singletons.h"

Renderer* g_renderer = NULL;
ResourceManager* g_resourceManager = NULL;
InputManager* g_inputManager = NULL;

void InitializeSingletons() {
		g_renderer = Renderer::GetInstance();
		g_resourceManager = ResourceManager::GetInstance();
		g_inputManager = InputManager::GetInstance();

		g_inputManager->SetWindow(g_renderer->GetWindow());

}