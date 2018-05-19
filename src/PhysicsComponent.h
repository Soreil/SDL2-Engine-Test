#pragma once
#include <SDL.h>
#include "Component.h"
#include "Entity.h"
#include <cstdint>

typedef int32_t int32;

class PhysicsComponent : public Component {
 public:
  SDL_Rect b_box;
  int32 _x, _y, _w, _h;
  
  void update();
  void update(Entity* entity);

  bool isColliding( Entity* collidable );

  PhysicsComponent( int32 x, int32 y, int32 w, int32 h  );
  ~PhysicsComponent();
  
  
};
