#ifndef  PLAYER_ATTACK_H
#define PLAYER_ATTACK_H

#include "Entity.h"

class PlayerAttack : public Entity {
public:
		PlayerAttack ();
		~PlayerAttack ();
		
		virtual void Update();
		virtual void Render(){}

private:
		virtual void UpdateInput();
		virtual void UpdateGraphics();
		bool m_isAttacking;
		Direction m_direction;
};

#endif // ! PLAYER_ATTACK_H
