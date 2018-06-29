#pragma once

#include "Entity.h"
#include "Vector2.h"

class Collider;

namespace Physics {

  /* The direction the collision came from, used for collision resolution */
  enum CollisionDirection {
    DIR_TOP,
    DIR_BOTTOM,
    DIR_LEFT,
    DIR_RIGHT
    
  };
  
  bool isColliding(Collider* a, Collider* b);
  Vec2 getCollisionVector(SAT_Rect* a, SAT_Rect* b);  
}
