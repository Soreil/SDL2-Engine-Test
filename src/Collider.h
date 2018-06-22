#pragma once
#include <SDL.h>
#include <cstdint>

#include "Vector2.h"

/* The direction the collision came from, used for collision resolution */
enum CollisionDirection {
  DIR_TOP,
  DIR_BOTTOM,
  DIR_LEFT,
  DIR_RIGHT
  
};

enum Quadrant {
  ONE = 1,
  TWO,
  THREE,
  FOUR
};

class Entity;

class Collider {
 public:
  SDL_Rect* b_box = nullptr;
  int32_t x, y, w, h;

  Quadrant quad;
  
 public:
  
  Quadrant getQuadrant( int x, int y );

  CollisionDirection getCollisionDirection( int ax, int ay, int bx, int by, int colResX, int colResY );
  
  void update(Entity* entity);

  bool isColliding( Collider* collidable );

  Vec2 getCollisionArea( Collider* collidable );
  
  Collider( int32_t _x, int32_t _y, int32_t _w, int32_t _h  );
  ~Collider();
  
  
};
