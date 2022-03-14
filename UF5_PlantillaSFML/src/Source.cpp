#include <SFML/Graphics.hpp>
#include "Singletons.h"
#include "Scene.h"

#include <iostream>

void MainLoop();

int main()
{
		InitializeSingetons();
		g_renderer->SetFramerateLimit(60);
		
		

	return 0;
}

void MainLoop() {
		g_renderer->SetFramerateLimit(60);
		const clock_t beginTime = clock();
		clock_t oldTime = beginTime;
		clock_t newTime = beginTime;

		Scene* currentScene = new Scene();

		while (g_renderer->IsWindowOpen()) {
				// Delta time update
				oldTime = newTime;
				newTime = clock() - beginTime;
				global_delta_time = int(newTime - oldTime);

				// Engine input update

				// Update and rende Scene
				currentScene->OnLoad();
				currentScene->OnUpdate();
				currentScene->OnRender();
		}

}