
#include "stdio.h"
#include "src/Vector2.h"
#include <stdlib.h>

enum SAT_Type {
  BASE_OBJ,
  RECTANGLE
};

class SAT_Object {
private:
  SAT_Type type;  
public:
  void setType(SAT_Type type) {
    this->type = type;
  }
};

class SAT_Rect {
public:
  int32_t x, y, w, h;
  Vec2 half_w, half_h;
  Vec2* center = nullptr;

public:  
  void init() {
    half_w.x = w/2;
  }
  
  ~SAT_Rect() {
    delete center;
    center = nullptr;
  }  
};


Vec2* getCollisionVector(SAT_Rect* a, SAT_Rect* b);

int main () {

  SAT_Rect a, b;

  a.x = 100;
  a.w = 64;
  a.y = 0;
  a.h = 0;
  a.center = new Vec2{ a.x + (a.w/2), 0 };
  a.init();

  b.x = 101;
  b.w = 64;
  b.y = 0;
  b.h = 0;
  b.center = new Vec2{ b.x + (b.w/2), 0 };
  b.init();
  
  auto projectionVec = getCollisionVector( &a, &b ); 
  
  delete projectionVec;
  projectionVec = nullptr;
  return 0;
}


  /* This function returns a vector, but only 1 value will be set, either x or y, depending on which
     is the projection vector. This function assumes a is SAT_Rect* a will be constant in all checks
     with other entities.  
  */
Vec2* getCollisionVector(SAT_Rect* a, SAT_Rect* b) {
  
  //a->center = new Vec2{ a->x + a->w/2, a->y + a->h/2 };
  
  int32_t distBetween;
  Vec2* projection = nullptr;
  
  //check if domains overlap
  if ( (a->x + a->w) > b->x && a->x < (b->x + b->w) ) {
    printf("Collision occured on X axis (desu)\n");
  
    if ( a->center->x >= b->center->x ) {
      distBetween = a->center->x - b->center->x;
      
      // halfwidth vector points towards the other object
      //flip the directions 
      a->half_w.x = -(a->w/2);
      b->half_w.x = (b->w)/2;
      
      projection = new Vec2{ abs(a->half_w.x) + b->half_w.x - distBetween, 0 };
      
    }
    else {
      distBetween = b->center->x - a->center->x;
      
      a->half_w.x =   a->w/2;
      b->half_w.x = -(b->w/2);
      
      projection = new Vec2{ a->half_w.x + abs(b->half_w.x) - distBetween, 0 };
      /*if a is less than (to the left of) b's center, then the projection vector's direction 
	is that of what will resolve the collision
      */
      projection->x *= -1;  
    }
    printf("Projection vector X:%d \n", projection->x);
    return projection;
  }
  else {    
    printf("meme not working \n");
    return projection;
  } 
}

