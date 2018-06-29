#include "Collider.h"
#include "Entity.h"



void Collider::update(Entity* entity) {
  x =          entity->position.x;
  y =          entity->position.y;
  sat_box->x = entity->position.x;
  sat_box->y = entity->position.y;

}




Collider::Collider( int32_t _x, int32_t _y, int32_t _w, int32_t _h ) {
  x = _x;
  y = _y;
  w = _w;
  h = _h;
  
  sat_box = new SAT_Rect{_x, _y, _w, _h};
}

Collider::~Collider() {
  delete sat_box;
  sat_box = nullptr;
}

