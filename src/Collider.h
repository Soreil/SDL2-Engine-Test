#pragma once
#include <SDL.h>
#include "Entity.h"
#include <cstdint>

#include "Vector2.h"

typedef int32_t int32;

class Collider {
 public:
  SDL_Rect b_box;
  int32 x, y, w, h;
 
  void update(Entity* entity);

  bool isColliding( Collider* collidable );

  Vec2 getCollisionArea( Collider* collidable );
  
  Collider( int32 _x, int32 _y, int32 _w, int32 _h  );
  ~Collider();
  
  
};
