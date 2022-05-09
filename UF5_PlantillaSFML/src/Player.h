#ifndef PLAYER_H
#define PLAYER_H

#include "includes.h"
#include "Singletons.h"
#include "Pawn.h"

class Player : public Pawn {
public:
		Player();
		~Player();

		virtual void Update();

		Direction GetDirection();
		void SetSpeed(int p_value) { m_speed = p_value; };
		int GetSpeed() { return m_speed; };
private:
		virtual void	UpdateInput();
		virtual void	UpdateGraphics();
		virtual void	Move();

		//Movement variables
		Direction	m_direction;
		Direction m_lastDirection;

};

#endif
