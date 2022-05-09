#include "Entity.h"
#include "Utils.h"

Entity::Entity() {
		m_rect = C_Rectangle{ 0,0, TILE_SIZE, TILE_SIZE };
		m_color = { 255,255,0 };

		m_imgRect = { 0,0, TILE_SIZE, TILE_SIZE };

		m_frame = 0;
		m_maxFrames = 8;
		m_currentFrameTime = 0;
		m_nextFrameTime = 100;

}

Entity::~Entity() {

}

void Entity::Update() { }
void Entity::Render() {
		g_renderer->DrawSprite(m_sprite, m_rect.x, m_rect.y, m_imgRect, Color{ 255,255,255 });
}
void Entity::UpdateInput() {}

void Entity::UpdateGraphics() {};

void Entity::SetX(int x) {
		m_rect.x = x;
}
void Entity::SetY(int y) {
		m_rect.y = y;
}
