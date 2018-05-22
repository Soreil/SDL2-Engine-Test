#pragma once
#include <SDL.h>
#include "Component.h"
#include "Entity.h"
#include <cstdint>

#include "Vector2.h"

typedef int32_t int32;

class PhysicsComponent : public Component {
 public:
  SDL_Rect b_box;
  int32 x, y, w, h;
  
  void update();
  void update(Entity* entity);

  bool isColliding( PhysicsComponent* collidable );

  Vec2 getCollisionArea( PhysicsComponent* collidable );
  
  PhysicsComponent( int32 _x, int32 _y, int32 _w, int32 _h  );
  ~PhysicsComponent();
  
  
};
