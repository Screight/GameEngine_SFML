#include "Pawn.h"
#include "Utils.h"

Pawn::Pawn() {
}
Pawn::~Pawn() {

}

void Pawn::Update() {

}

void Pawn::UpdateGraphics() {
		
};

void Pawn::UpdateInput() {

}

void Pawn::Move() {

}

void Pawn::SetX(int p_x) {
		Entity::SetX(p_x);
		m_XToGo = p_x;
}
void Pawn::SetY(int p_y) {
		Entity::SetY(p_y);
		m_YToGo = p_y;
}

void Pawn::SetCollisionMap(std::vector<std::vector<bool>>* colMap) {
		m_collisionMap = colMap;
		m_mapH = (*m_collisionMap).size();
		if (m_mapH > 0) { m_mapW = (*m_collisionMap)[0].size(); }

};

bool Pawn::GetCollisionWithMap(int x, int y) {
		int tileX = x / TILE_SIZE;
		int tileY = y / TILE_SIZE;
		if (tileX == -1 || tileX == m_mapW) { return false; }
		if (tileX < 0 || tileX >= m_mapW || tileY < 0 || tileY >= m_mapH) { return true; }
		return (*m_collisionMap)[tileY][tileX];
}

/*bool Entity::GetCollisionWithGhost(Ghost p_ghost) {
		if (C_RectangleCollision(p_ghost.getRect(), mRect) && (mRect.x == p_ghost.getRect().x || mRect.y == p_ghost.getRect().y)) {
				return true;
		}
		return false;
}*/

Direction Pawn::GetDirection() {
		return m_direction;
}
