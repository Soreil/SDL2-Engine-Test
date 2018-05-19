#include "PhysicsComponent.h"


void PhysicsComponent::update() {

}

void PhysicsComponent::update(Entity* entity) {
  
}


PhysicsComponent::PhysicsComponent( int32 x, int32 y, int32 w, int32 h ) {
  _x = x;
  _y = y;
  _w = w;
  _h = h;
  b_box = SDL_Rect{x, y, w, h};
}

PhysicsComponent::~PhysicsComponent() {
  
}

