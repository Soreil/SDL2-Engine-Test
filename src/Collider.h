#pragma once
#include <SDL.h>
#include <cstdint>

#include "Vector2.h"

class Entity;

class Collider {
 public:
  SDL_Rect b_box;
  int32_t x, y, w, h;
 
  void update(Entity* entity);

  bool isColliding( Collider* collidable );

  Vec2 getCollisionArea( Collider* collidable );
  
  Collider( int32_t _x, int32_t _y, int32_t _w, int32_t _h  );
  ~Collider();
  
  
};
