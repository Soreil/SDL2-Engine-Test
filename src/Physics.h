#pragma once

#include "Entity.h"
#include "Vector2.h"


namespace Physics {


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
  

  

  CollisionDirection getCollisionDirection( int ax, int ay, int bx, int by, int colResX, int colResY );
  
  // entity is the entity to be displaced by vector 'displacement'
  void resolveCollision( Entity* entity, CollisionDirection dir, Vec2 displacement );
  
  
}
