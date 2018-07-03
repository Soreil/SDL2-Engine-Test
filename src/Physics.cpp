#include "Physics.h"

#include "Collider.h"
#include "SAT.h"


bool Physics::isColliding( Collider* a, Collider* b ) {
  
  if ( a && b) {
  
    SAT_Rect* sat_a = a->sat_box;
    SAT_Rect* sat_b = b->sat_box;

    // b_box = sat_a :  cBox = sat_b
    
    if ( sat_a->x < sat_b->x + sat_b->w && sat_b->x < sat_a->x + sat_a->w &&
	 sat_a->y < sat_b->y + sat_b->h && sat_b->y < sat_a->y + sat_a->h    ) {

      sat_a = nullptr;
      sat_b = nullptr;
      return true;
    }
    else {
      sat_a = nullptr;
      sat_b = nullptr;
      return false;
    }
  }
}

/* This function returns a vector, but only 1 value will be set, either x or y, depending on which
   is the projection vector. This function assumes a is SAT_Rect* a will be constant in all checks
   with other entities.  
*/
Vec2 Physics::getCollisionVector(SAT_Rect* a, SAT_Rect* b) {
  int32_t distBetween;
  Vec2 projection;
  
  // UPDATE CENTERS
  a->center->x = a->x + (a->w/2);
  a->center->y = a->y + (a->h/2);
  
  b->center->x = b->x + (b->w/2);
  b->center->y = b->y + (b->h/2);
  
  // HANDLE X STUFF   
  if ( a->center->x >= b->center->x ) {
    distBetween = a->center->x - b->center->x;
    
    // halfwidth vector points towards the other object
    //flip the directions 
    a->half_w.x = -(a->w/2);
    b->half_w.x = (b->w)/2;
    
    projection.x = (a->w/2) + (b->w/2) - distBetween;
  }
  else {
    distBetween = b->center->x - a->center->x;
    
    a->half_w.x =   a->w/2;
    b->half_w.x = -(b->w/2);
    
    projection.x = (a->w/2) + (b->w/2) - distBetween;
    /*if a is less than (to the left of) b's center, then the projection vector's direction 
      is that of what will resolve the collision */
    projection.x *= -1;  
  }
  
  //HANDLE Y
  if ( a->center->y >= b->center->y ) {
    distBetween = a->center->y - b->center->y;
    
    a->half_h.y = -(a->h/2);
    b->half_h.y =   a->h/2;
    
    projection.y = (a->h/2) + (b->h/2) - distBetween; 
  }
  else {
    distBetween = b->center->y - a->center->y;
    
    a->half_h.y =   a->h/2;
    b->half_h.y = -(a->h/2);
    
    projection.y = (a->h/2) + (b->h/2) - distBetween;
    projection.y *= -1;
  } 
  
  //printf("Projection vector: X:%d  Y:%d \n", projection.x, projection.y);   
  // Axis with the smallest overlap means the collision occured on that axis, so resolution
  // needs to resolve using that axis' projection. 
  abs(projection.x) > abs(projection.y) ?  projection.x = 0 : projection.y = 0;
  
  return projection; 
}



