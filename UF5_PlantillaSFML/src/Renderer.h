#ifndef RENDERER_H
#define RENDERER_H

#include "includes.h"
#include <SFML/Graphics.hpp>

// PROXY RENDER
// IS A SINGLETON

class Renderer {
public: 

		static Renderer* GetInstance();

		//! Inits the screen
		void InitializeWindow();

		sf::RenderWindow* GetWindow() { return m_window; }

		//! Cleans the Screen (render a solid black)
		void ClearWindow();

		//! Perfomrs the screen Draw (screen flip)
		void RefreshWindow();

		void SetFramerateLimit(int p_framerate);
		const int& GetFramerateLimit() { return m_frameRateLimit; }

		bool IsWindowOpen();

		// Shape functions

		/// <summary>
		/// Draws a rectangle
		/// </summary>
		/// <param name="p_rectangle">Rectangle(position, width and height)</param>
		/// <param name="p_color">RGB components</param>
		/// <param name="p_outline">Determines if the rectangle is filled or made of outlines</param>
		void DrawRectangle(C_Rectangle p_rectangle, Color p_color, bool p_outline = false);

		/// <summary>
		/// 
		/// </summary>
		/// <param name="p_rectangle">Rectangle(position, width and height)</param>
		/// <param name="p_color_1">Color top left (R,G,B)</param>
		/// <param name="p_color_2">Color top right(R,G,B)</param>
		/// <param name="p_color_3">Color bottom left (R,G,B)</param>
		/// <param name="p_color_4">Color bottom right (R,G,B)</param>
		void DrawRectangleGradient(C_Rectangle p_rectangle, Color p_color_1, Color p_color_2, Color p_color_3, Color p_color_4);

		void DrawCircle();

		/// <summary>
		/// Draws a sprite with it cut-off rectangle
		/// </summary>
		/// <param name="p_id"> the id of the sprite to render</param>
		/// <param name="p_positionX"></param>
		/// <param name="p_positionY"></param>
		/// <param name="p_cutOffRectangle"> a rectangle that represents the area of the image that is gonna be rendered</param>
		/// <param name="p_color"></param>
		void DrawSprite(int p_id, int p_positionX, int p_positionY, C_Rectangle p_cutOffRectangle, Color p_color = {255,255,255});

		/// <summary>
/// Draws a sprite with it cut-off rectangle
/// </summary>
/// <param name="p_id"> the id of the sprite to render</param>
/// <param name="p_positionX"></param>
/// <param name="p_positionY"></param>
/// <param name="p_cutOffRectangle"> a rectangle that represents the area of the image that is gonna be rendered</param>
/// <param name="p_color"></param>
		void DrawSprite(int p_id, int p_positionX, int p_positionY, Color p_color = { 255,255,255 });

private:
		Renderer();
		~Renderer();

		static Renderer*		m_instance;
		sf::RenderWindow*		m_window;

		int									m_windowWidth;
		int									m_windowHeight;

		int									m_frameRateLimit;


};


#endif // ! RENDERER_H
