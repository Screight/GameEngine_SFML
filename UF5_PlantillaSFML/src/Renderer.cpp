#include "Renderer.h"

Renderer* Renderer::p_instance = NULL;

Renderer* Renderer::GetInstance() {
		if (p_instance == NULL) {
				p_instance = new Renderer();
		}
		return p_instance;
}

Renderer::Renderer(): m_window(NULL) {
		InitializeWindow();
}

Renderer::~Renderer() { delete(m_window); }

void Renderer::InitializeWindow() {
		m_windowWidth = SCREEN_WIDTH;
		m_windowHeight = SCREEN_HEIGHT;
		m_window = new sf::RenderWindow(sf::VideoMode(m_windowWidth, m_windowHeight), WINDOW_TITLE);
}

void Renderer::ClearWindow() {
		m_window->clear(sf::Color::Black);
}

void Renderer::RefreshWindow() {
		m_window->display();
}

void Renderer::SetFramerateLimit(int p_framerateLimit) {
		m_frameRateLimit = p_framerateLimit;
		m_window->setFramerateLimit(m_frameRateLimit);
}

bool Renderer::IsWindowOpen() { return m_window->isOpen(); }

void Renderer::DrawRectangle(C_Rectangle p_rectangle, Color p_color, bool p_outline) {
		sf::RectangleShape rectangleShape;
		sf::Color color = sf::Color(p_color.red, p_color.green, p_color.blue);
		
		if (!p_outline) rectangleShape.setFillColor(color);
		else rectangleShape.setFillColor(sf::Color(0, 0, 0, 0));

		rectangleShape.setOutlineThickness(1);
		rectangleShape.setOutlineColor(color);
		rectangleShape.setPosition(sf::Vector2f(p_rectangle.x, p_rectangle.y));
		rectangleShape.setSize(sf::Vector2f(p_rectangle.w, p_rectangle.h));

		m_window->draw(rectangleShape);
}

void Renderer::DrawRectangleGradient(C_Rectangle p_rectangle, Color p_color_1, Color p_color_2, Color p_color_3, Color p_color_4) {
		sf::Vector2f point_1 = sf::Vector2f(p_rectangle.x, p_rectangle.y);
		sf::Vector2f point_2 = sf::Vector2f(p_rectangle.x + p_rectangle.w, p_rectangle.y);
		sf::Vector2f point_3 = sf::Vector2f(p_rectangle.x + p_rectangle.w, p_rectangle.y + p_rectangle.h);
		sf::Vector2f point_4 = sf::Vector2f(p_rectangle.x, p_rectangle.y + p_rectangle.h);

		sf::Color color_1 = sf::Color(p_color_1.red, p_color_1.green, p_color_1.blue);
		sf::Color color_2 = sf::Color(p_color_2.red, p_color_2.green, p_color_2.blue);
		sf::Color color_3 = sf::Color(p_color_3.red, p_color_3.green, p_color_3.blue);
		sf::Color color_4 = sf::Color(p_color_4.red, p_color_4.green, p_color_4.blue);

		sf::Vertex rectangle[] = {
				sf::Vertex(point_1, color_1),
				sf::Vertex(point_2, color_2),
				sf::Vertex(point_3, color_3),
				sf::Vertex(point_4, color_4)
		};

		m_window->draw(rectangle, 4, sf::Quads);

}

void Renderer::DrawCircle() {

}