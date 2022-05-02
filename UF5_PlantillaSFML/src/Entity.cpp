#include "Entity.h"
#include "Utils.h"

Entity::Entity() {
		mRect = C_Rectangle{ 0,0, TILE_SIZE, TILE_SIZE };
		mColor = { 255,255,0 };

		mDirection = Direction::NONE;
		mMoving = false;
		mXtoGo = 0;
		mYtoGo = 0;

		mSpeed = 200;

		mSprite = g_resourceManager->GetSpriteID("assets/link_walk_bottom.png");
		mImgRect = { 0,0, TILE_SIZE, TILE_SIZE };

		mFrame = 0;
		mMaxFrames = 8;
		mCurrentFrameTime = 0;
		mNextFrameTime = 100;

		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_top.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_bottom.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_left.png") });
		m_animations.push_back(Animations{ 8, g_resourceManager->GetSpriteID("assets/link_walk_right.png") });

}
Entity::~Entity() {

}

void Entity::update() {

		move();
		if (!mMoving) { updateInput(); }
		else {

		}
		updateGraphics();
}
void Entity::render() {
		g_renderer->DrawSprite(mSprite, mRect.x, mRect.y, mImgRect, Color{255,255,255});
}

void Entity::updateGraphics() {
		if (mDirection != Direction::NONE) {
				mSprite = m_animations[(int)mDirection - 1].sprite;
		}
		if (mMoving) {
				mCurrentFrameTime += global_delta_time;
				if (mCurrentFrameTime >= mNextFrameTime) {
						mCurrentFrameTime -= mNextFrameTime;
						mFrame++;
						if (mFrame >= mMaxFrames) {
								mFrame = 0;
						}
				}
		}
		else {
				mFrame = 0;
				mCurrentFrameTime = 0;
		}

		mImgRect.x = mFrame * mImgRect.w;
};

void Entity::updateInput() {

		int newXtoGo = mXtoGo;
		int newYtoGo = mYtoGo;

		if (mMoving) { return; }

		mDirection = Direction::NONE;
		if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_W)) {
				mDirection = Direction::UP;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_S)) {
				mDirection = Direction::DOWN;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_A)) {
				mDirection = Direction::LEFT;
		}
		else if (g_inputManager->IsKeyDown(InputManager::KeyboardKeys::KEY_D)) {
				mDirection = Direction::RIGHT;
		}

		if (mDirection != Direction::NONE) {
				mMoving = true;
				switch (mDirection)
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
		if (!getCollisionWithMap(newXtoGo, newYtoGo)) {
				mXtoGo = newXtoGo;
				mYtoGo = newYtoGo;
		}
		else {
				mMoving = false;
		}
}

void Entity::move() {
		if (!mMoving) { return; }

		int speedX = 0;
		int speedY = 0;

		int prevX = mRect.x;
		int prevY = mRect.y;

		if (mRect.x < mXtoGo) {
				speedX = mSpeed;
		}
		else if (mRect.x > mXtoGo) {
				speedX = -mSpeed;
		}

		if (mRect.y < mYtoGo) {
				speedY = mSpeed;
		}
		else if (mRect.y > mYtoGo) {
				speedY = -mSpeed;
		}

		//Movimiento
		mRect.x = mRect.x + speedX * (int)global_delta_time / 1000;
		mRect.y = mRect.y + speedY * (int)global_delta_time / 1000;

		if ((prevX < mXtoGo && mRect.x > mXtoGo) || (prevX > mXtoGo && mRect.x < mXtoGo)) {
				mRect.x = mXtoGo;
		}
		if ((prevY < mYtoGo && mRect.y > mYtoGo) || (prevY > mYtoGo && mRect.y < mYtoGo)) {
				mRect.y = mYtoGo;
		}

		if (mRect.x == mXtoGo && mRect.y == mYtoGo) {
				//Llego al destino
				mMoving = false;
		}
}

void Entity::setX(int x) {
		mRect.x = x;
		mXtoGo = x;
}
void Entity::setY(int y) {
		mRect.y = y;
		mYtoGo = y;
}

void Entity::setCollisionMap(std::vector<std::vector<bool>>* colMap) {
		mpCollisionMap = colMap;
		mMapH = (*mpCollisionMap).size();
		if (mMapH > 0) { mMapW = (*mpCollisionMap)[0].size(); }

};

bool Entity::getCollisionWithMap(int x, int y) {
		int tileX = x / TILE_SIZE;
		int tileY = y / TILE_SIZE;
		if (tileX == -1 || tileX == mMapW) { return false; }
		if (tileX < 0 || tileX >= mMapW || tileY < 0 || tileY >= mMapH) { return true; }
		return (*mpCollisionMap)[tileY][tileX];
}

/*bool Entity::GetCollisionWithGhost(Ghost p_ghost) {
		if (C_RectangleCollision(p_ghost.getRect(), mRect) && (mRect.x == p_ghost.getRect().x || mRect.y == p_ghost.getRect().y)) {
				return true;
		}
		return false;
}*/

Direction Entity::GetDirection() {
		return mDirection;
}
