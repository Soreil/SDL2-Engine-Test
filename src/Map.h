#pragma once

#include <SDL.h>
#include "Collider.h"
#include "Physics.h"
#include <cstdint>

const uint32_t MAX_WALL_COLLIDERS = 128;

class Map {
 private:
  Collider* walls[MAX_WALL_COLLIDERS];
  
 public:
  int tileWidth = 32;
  int tileHeight = 32;
  
  void load();
  
  void update(float dt);

  void render(SDL_Renderer* r);

  Map();
  ~Map();
  

};
