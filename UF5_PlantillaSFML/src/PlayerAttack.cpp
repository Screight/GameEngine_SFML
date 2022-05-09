#include "PlayerAttack.h"

PlayerAttack::PlayerAttack()
{
		m_isAttacking = false;

		m_rect = C_Rectangle{ 0,0, TILE_SIZE, TILE_SIZE };
		m_color = { 255,255,0 };

		m_imgRect = { 0,0, TILE_SIZE, TILE_SIZE };

		m_frame = 0;
		m_maxFrames = 7;
		m_currentFrameTime = 0;
		m_nextFrameTime = 100;

		m_animations.push_back(Animations{ 7, g_resourceManager->GetSpriteID("assets/empty_sprite.png") });
		m_animations.push_back(Animations{ 7, g_resourceManager->GetSpriteID("assets/link_attack_top.png") });
		m_animations.push_back(Animations{ 7, g_resourceManager->GetSpriteID("assets/link_attack_bottom.png") });
		m_animations.push_back(Animations{ 7, g_resourceManager->GetSpriteID("assets/link_attack_left.png") });
		m_animations.push_back(Animations{ 7, g_resourceManager->GetSpriteID("assets/link_attack_right.png") });
}

PlayerAttack::~PlayerAttack(){}

void PlayerAttack::Update() {

}

void PlayerAttack::UpdateInput() {
		if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::SPACE)) {
				m_direction = Direction::UP;
		}
}

void PlayerAttack::UpdateGraphics(){

		m_sprite = m_animations[(int)m_direction].sprite;

		if (m_isAttacking) {
				m_currentFrameTime += global_delta_time;
				if (m_currentFrameTime >= m_nextFrameTime) {
						m_currentFrameTime -= m_nextFrameTime;
						m_frame++;
						if (m_frame >= m_maxFrames) {
								m_frame = 0;
								m_isAttacking = false;
						}
				}
		}
		else {
				m_frame = 0;
				m_currentFrameTime = 0;
		}

		m_imgRect.x = m_frame * m_imgRect.w;
}

