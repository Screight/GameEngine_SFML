#include <SFML/Graphics.hpp>
#include "Singletons.h"
#include "SceneMenu.h"

#include <iostream>

unsigned int global_delta_time;

void MainLoop();

int main()
{
		InitializeSingletons();
		g_renderer->SetFramerateLimit(60);
		
		MainLoop();

		return 0;
}

void MainLoop() {
		g_renderer->SetFramerateLimit(60);
		const clock_t beginTime = clock();
		clock_t oldTime = beginTime;
		clock_t newTime = beginTime;

		Scene* currentScene = new SceneMenu();

		while (g_renderer->IsWindowOpen()) {
				// Delta time update
				oldTime = newTime;
				newTime = clock() - beginTime;
				global_delta_time = int(newTime - oldTime);

				// Engine input update
				g_inputManager->UpdateEvents();

				// Update and rende Scene
				currentScene->OnLoad();
				currentScene->OnUpdate();
				currentScene->OnRender();
		}
		std::cout << "patata";
}