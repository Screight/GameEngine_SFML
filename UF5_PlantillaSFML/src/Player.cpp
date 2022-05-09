#include "Player.h"
#include "Utils.h"

Player::Player() {
		m_rect = C_Rectangle{ 0,0, TILE_SIZE, TILE_SIZE };
		m_color = { 255,255,0 };

		m_direction = Direction::NONE;
		m_lastDirection = Direction::RIGHT;
		m_moving = false;
		m_XToGo = 0;
		m_YToGo = 0;

		m_speed = 200;

		m_sprite = g_resourceManager->GetSpriteID("assets/link_walk_bottom.png");
		m_imgRect = { 0,0, TILE_SIZE, TILE_SIZE };

		m_frame = 0;
		m_maxFrames = 8;
		m_currentFrameTime = 0;
		m_nextFrameTime = 100;

		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_top.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_bottom.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_left.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_right.png") });

		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_idle_top.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_idle_bottom.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_idle_left.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_idle_right.png") });

}
Player::~Player() {

}

void Player::Update() {

		Move();
		if (!m_moving) { UpdateInput(); }
		else {

		}
		UpdateGraphics();
}

void Player::UpdateGraphics() {
		if (m_direction != Direction::NONE) {
				m_sprite = m_animations[(int)m_direction - 1].sprite;
		}
		else {
				m_sprite = m_animations[(int)m_lastDirection - 1 + 4].sprite;
		}

		if (m_moving) {
				m_currentFrameTime += global_delta_time;
				if (m_currentFrameTime >= m_nextFrameTime) {
						m_currentFrameTime -= m_nextFrameTime;
						m_frame++;
						if (m_frame >= m_maxFrames) {
								m_frame = 0;
						}
				}
		}
		else {
				m_frame = 0;
				m_currentFrameTime = 0;
		}

		m_imgRect.x = m_frame * m_imgRect.w;
};

void Player::UpdateInput() {

		int newXtoGo = m_XToGo;
		int newYtoGo = m_YToGo;

		if (m_moving) { return; }

		m_direction = Direction::NONE;
		if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_W)) {
				m_direction = Direction::UP;
				m_lastDirection = Direction::UP;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_S)) {
				m_direction = Direction::DOWN;
				m_lastDirection = Direction::DOWN;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_A)) {
				m_direction = Direction::LEFT;
				m_lastDirection = Direction::LEFT;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_D)) {
				m_direction = Direction::RIGHT;
				m_lastDirection = Direction::RIGHT;
		}

		if (m_direction != Direction::NONE) {
				m_moving = true;
				switch (m_direction)
				{
				case Direction::UP:
						newYtoGo -= TILE_SIZE;
						break;
				case Direction::DOWN:
						newYtoGo += TILE_SIZE;
						break;
				case Direction::LEFT:
						newXtoGo -= TILE_SIZE;
						break;
				case Direction::RIGHT:
						newXtoGo += TILE_SIZE;
						break;
				default:
						break;
				}
		}
		if (!GetCollisionWithMap(newXtoGo, newYtoGo)) {
				m_XToGo = newXtoGo;
				m_YToGo = newYtoGo;
		}
		else {
				m_moving = false;
		}
}

void Player::Move() {
		if (!m_moving) { return; }

		int speedX = 0;
		int speedY = 0;

		int prevX = m_rect.x;
		int prevY = m_rect.y;

		if (m_rect.x < m_XToGo) {
				speedX = m_speed;
		}
		else if (m_rect.x > m_XToGo) {
				speedX = -m_speed;
		}

		if (m_rect.y < m_YToGo) {
				speedY = m_speed;
		}
		else if (m_rect.y > m_YToGo) {
				speedY = -m_speed;
		}

		//Movimiento
		m_rect.x = m_rect.x + speedX * (int)global_delta_time / 1000;
		m_rect.y = m_rect.y + speedY * (int)global_delta_time / 1000;

		if ((prevX < m_XToGo && m_rect.x > m_XToGo) || (prevX > m_XToGo && m_rect.x < m_XToGo)) {
				m_rect.x = m_XToGo;
		}
		if ((prevY < m_YToGo && m_rect.y > m_YToGo) || (prevY > m_YToGo && m_rect.y < m_YToGo)) {
				m_rect.y = m_YToGo;
		}

		if (m_rect.x == m_XToGo && m_rect.y == m_YToGo) {
				//Llego al destino
				m_moving = false;
		}
}

/*bool Entity::GetCollisionWithGhost(Ghost p_ghost) {
		if (C_RectangleCollision(p_ghost.getRect(), mRect) && (mRect.x == p_ghost.getRect().x || mRect.y == p_ghost.getRect().y)) {
				return true;
		}
		return false;
}*/

Direction Player::GetDirection() {
		return m_direction;
}
