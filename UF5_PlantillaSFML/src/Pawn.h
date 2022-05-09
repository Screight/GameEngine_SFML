#ifndef PAWN_H
#define PAWN_H

#include "includes.h"
#include "Singletons.h"
#include "Entity.h"

class Pawn : public Entity{
public:
		Pawn();
		~Pawn();

		void SetCollisionMap(std::vector<std::vector<bool>>* p_colMap);

		virtual void Update() = 0;

		Direction GetDirection();
		void SetSpeed(int p_value) { m_speed = p_value; };
		int GetSpeed() { return m_speed; };
		virtual void SetX(int p_x);
		virtual void SetY(int p_x);

protected:
		virtual void	Move() = 0;
		virtual void UpdateGraphics() = 0;
		virtual void UpdateInput() = 0;

		bool GetCollisionWithMap(int p_x, int p_y);

		std::vector<std::vector<bool>>* m_collisionMap;
		int m_mapH;
		int m_mapW;

		//Movement variables
		Direction	m_direction;
		Direction m_lastDirection;
		int			m_XToGo;
		int			m_YToGo;
		bool		m_moving;
		int			m_speed;

		std::vector<Animations> m_animations;

};

#endif
