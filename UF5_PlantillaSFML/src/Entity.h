#pragma once
#ifndef PACMAN_H
#define PACMAN_H

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

		void update();
		void render();

		void setX(int x);
		void setY(int y);

		void setCollisionMap(std::vector<std::vector<bool>>* colMap);
		C_Rectangle getRect() { return mRect; }

		Direction GetDirection();
		void SetSpeed(int p_value) { mSpeed = p_value; };
		int GetSpeed() { return mSpeed; };
private:
		void	updateInput();
		void	updateGraphics();
		void	move();

		bool getCollisionWithMap(int x, int y);

		Color		mColor;
		C_Rectangle	mRect;

		std::vector<std::vector<bool>>* mpCollisionMap;
		int mMapH;
		int mMapW;

		//Movement variables
		Direction	mDirection;
		int			mXtoGo;
		int			mYtoGo;
		bool		mMoving;
		int			mSpeed;

		int mSprite;
		C_Rectangle mImgRect;

		int mFrame;
		int mMaxFrames;
		int mCurrentFrameTime;
		int mNextFrameTime;

		std::vector<Animations> m_animations;

};

#endif
