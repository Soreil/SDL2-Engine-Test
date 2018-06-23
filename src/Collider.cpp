#include "Collider.h"
#include "Entity.h"


void Collider::update(Entity* entity) {
  
}


bool Collider::isColliding(Collider* collidable) {

  SDL_Rect* cBox = collidable->b_box;
  
  if (collidable && b_box) {
    if ( b_box->x < cBox->x + cBox->w && cBox->x < b_box->x + b_box->w &&
	 b_box->y < cBox->y + cBox->h && cBox->y < b_box->y + b_box->h    ) {
      return true;
    }
    else {
      return false;
    }
  }
  
  cBox = nullptr;
  
}

/*
Quadrant Collider::getQuadrant(int x, int y) {
  if ( x > 0 && y < 0 ) {
    return Quadrant::ONE;
  }
  else if ( x < 0 && y < 0 ) {
    return Quadrant::TWO;
  }
  else if ( x < 0 && y > 0 ) {
    return Quadrant::THREE;
  }
  else if ( x > 0 && y > 0 ) {
    return Quadrant::FOUR;
  }
}
*/


Vec2 Collider::getCollisionArea(Collider* collidable) {
  
  int32_t maxLength;
  int32_t currLength;

  int32_t maxHeight;
  int32_t currHeight;


  SDL_Rect* a = nullptr;
  SDL_Rect* b = nullptr;

  a = b_box;
  b = collidable->b_box;

  /*
  //Store Quadrants for later
  this->quad       = getQuadrant( a->x, a->y );
  collidable->quad = getQuadrant( b->x, b->y );
  */

  
  maxLength = a->w + b->w;
  maxHeight = a->h + b->h;  
  
  //TODO(sweets): Look into using absoloute values + taking negative
  
  // X STUFF
  if ( b->x >= 0 ) {
    maxLength = a->w + b->w;
    currLength = ( b->x + b->w ) - ( a->x ) ;
  } else {
    maxLength = a->w + (-b->w);
    currLength = ( b->x + (-b->w)  ) - ( a->x ) ;
  }

  // Y STUFF
  if ( b->y >= 0 ) {  
    maxHeight = a->y + b->y;
    currHeight = ( b->y + b->w ) - (a->y) ;
  } else {
    maxHeight = a->y + (-b->y);
    currHeight = ( b->y + (-b->w) ) - (a->y) ;
  }

  int32_t collArea_X = currLength - maxLength;       //Returns - if colliding from the left
  int32_t collArea_Y = currHeight - maxHeight;       //Returns - if colliding from the top

  printf("Collision: X: %d  Y: %d  \n", collArea_X, collArea_Y);

  a = nullptr;
  b = nullptr;

  return Vec2( collArea_X, collArea_Y );    
}


Collider::Collider( int32_t _x, int32_t _y, int32_t _w, int32_t _h ) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  
  b_box = new SDL_Rect{_x, _y, _w, _h};
  printf(" x: %d   y: %d    w: %d    h: %d \n", b_box->x, b_box->y, b_box->w, b_box->h);
  
}

Collider::~Collider() {
  delete b_box;
  b_box = nullptr;
}

