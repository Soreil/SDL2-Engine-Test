#include "Physics.h"



Physics::CollisionDirection Physics::getCollisionDirection( int ax, int ay,
							    int bx, int by,
							    int colResX, int colResY ) {
  if ( colResX > colResY ) {
    if ( ax < bx ) {
      return CollisionDirection::DIR_LEFT;
    }
    else if ( ax > bx ) {
      return CollisionDirection::DIR_RIGHT;
    }
  }
  else if ( colResX <= colResY ) {
    if ( ay < by ) {
      return CollisionDirection::DIR_TOP;
    }
    else if ( ay > by ) {
      return CollisionDirection::DIR_BOTTOM;
    }
  }
}


void Physics::resolveCollision( Entity* entity, CollisionDirection dir, Vec2 displacement ) {
  entity->collider->x = displacement.x;
  entity->collider->y = displacement.y;    
}
  
