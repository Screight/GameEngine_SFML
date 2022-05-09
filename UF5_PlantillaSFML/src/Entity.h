#ifndef ENTITY_H
#define ENTITY_H

#include "includes.h"
#include "Singletons.h"

typedef struct {
		int numberOfFrames;
		int sprite;

}Animations;

class Entity {
public:
		Entity();
		~Entity();

		virtual void Update() = 0;
		virtual void Render() = 0;

		virtual void SetX(int x);
		virtual void SetY(int y);
		C_Rectangle GetRect() { return m_rect; }

protected:
		virtual void	UpdateInput() = 0;
		virtual void	UpdateGraphics() = 0;

		Color		m_color;
		C_Rectangle	m_rect;

		int m_sprite;
		C_Rectangle m_imgRect;

		int m_frame;
		int m_maxFrames;
		int m_currentFrameTime;
		int m_nextFrameTime;

		std::vector<Animations> m_animations;

};

#endif
