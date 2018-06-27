
#include "SAT.h"




SAT_Rect::SAT_Rect(int32_t x, int32_t y, int32_t w, int32_t h) : x(x), y(y), w(w), h(h) {
  half_w.x = w/2;
  half_h.y = h/2;

  center = new Vec2{ x + w/2, y + h/2 };
}


SAT_Rect::~SAT_Rect() {
  delete center;
  center = nullptr;
}




  /* This function returns a vector, but only 1 value will be set, either x or y, depending on which
     is the projection vector. This function assumes a is SAT_Rect* a will be constant in all checks
     with other entities.  
  */
Vec2 SAT::getCollisionVector(SAT_Rect* a, SAT_Rect* b) {
  
  //a->center = new Vec2{ a->x + a->w/2, a->y + a->h/2 };
  
  int32_t distBetween;
  Vec2 projection;
  
  //check if domains overlap
  if ( (a->x + a->w) > b->x && a->x < (b->x + b->w) &&
       a->y < (b->y + b->w) && (a->y + a->w) > b->y ) {


    /*
      HANDLE X STUFF
     */
    printf("Collision occured on X axis (desu)\n");
  
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
	is that of what will resolve the collision
      */
      projection.x *= -1;  
    }


    /*
      HANDLE Y
     */


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
    
    printf("Projection vector: X:%d  Y:%d \n", projection.x, projection.y);
    return projection;
  }
  else {    
    printf("meme not working \n");
    return projection;
  } 
}

