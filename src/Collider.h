#pragma once
#include <SDL.h>
#include <cstdint>

#include "Vector2.h"

#include "SAT.h"


class Entity;

class Collider {
 public:
  int32_t x, y, w, h;
  SAT_Rect* sat_box = nullptr;
  
 public:
  
  void update(Entity* entity);
  
  Collider( int32_t _x, int32_t _y, int32_t _w, int32_t _h  );
  ~Collider();
  
  
};
