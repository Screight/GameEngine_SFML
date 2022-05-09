#ifndef INCLUDES_H
#define INCLUDES_H

#include <string>
#include <stack>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "math.h"
#include <map>

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#define WINDOW_TITLE "WINDOW"

#define TILE_SIZE 32

//! Struct C_Rectangle.
typedef struct { 
	  int x;
	  int y;
	  unsigned int w;
	  unsigned int h;
} C_Rectangle;

//! Struct Point.
/*! A point in 2D. */
struct Point { 
	int x;
	int y;

	bool operator==(const Point& a) const
	{
		return (x == a.x && y == a.y);
	}
	bool operator!=(const Point& a) const
	{
		return (x != a.x || y != a.y);
	}
};

//! Struct Color
typedef struct {
		unsigned int red;
		unsigned int green;
		unsigned int blue;
}Color;

//! Struct Triangle.
/*! Struct that consists of 3 points. */
typedef struct { 
	Point a;
	Point b;
	Point c;
} C_Triangle;

// Tiempo pasado entre frames
extern unsigned int global_delta_time;


//Eliminar vectores de punteros
template <class C> void FreeClear( C & cntr ) {
    for ( typename C::iterator it = cntr.begin(); 
              it != cntr.end(); ++it ) {
    	delete * it;
    }
    cntr.clear();
	cntr.shrink_to_fit(); //Hace que la memoria reservada sea la necesaria para el nuevo tamaño (0)
}

enum class Direction { NONE, UP, DOWN, LEFT, RIGHT, LAST_NO_USE };
enum class PlayerAnimations { WALK_TOP, WALK_BOTTOM, WALK_LEFT, WALK_RIGHT, IDLE_TOP, IDLE_BOTTOM, IDLE_LEFT, IDLE_RIGHT, LAST_NO_USE };
enum class PlayerAttack { ATTACK_TOP, ATTACK_BOTTOM, ATTACK_LEFT, ATTACJ_RIGHT, LAST_NO_USE};

#endif
