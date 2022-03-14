#include <SFML/Graphics.hpp>
#include "Renderer.h"
#include <iostream>

int main()
{
		Renderer* render = Renderer::GetInstance();
		render->SetFramerateLimit(60);
		

		while (true) {
				render->ClearWindow();
				render->DrawRectangle(C_Rectangle{100,100,50,50}, Color{ 0,0,255 }, true);
				render->DrawRectangleGradient(	C_Rectangle{200,200,50,50 },
																				Color{ 255,0,0 },
																				Color{ 0,255,0 },
																				Color{ 0,0,255 },
																				Color{ 255,0,255 });
				render->RefreshWindow();
		}

	return 0;
}