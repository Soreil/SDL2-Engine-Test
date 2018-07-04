#pragma once

#include <SDL.h>
#include "Collider.h"
#include "Physics.h"
#include <cstdint>
#include <map>

class ResourceManager;

const uint32_t MAX_WALL_COLLIDERS = 128;

class Map {
 private:

  SDL_Texture* atlasTexture = nullptr;
  
  Collider* walls[MAX_WALL_COLLIDERS];


  std::map<std::string, SDL_Rect*> atlasLocs;
  
  static const uint16_t MAP_WIDTH = 4;
  static const uint16_t MAP_HEIGHT = 4;

  const int map[MAP_WIDTH][MAP_HEIGHT] = {
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 },
    { 1, 1, 1, 1 }
  };
  
 public:
  const int tileWidth = 32;
  const int tileHeight = 32;
  
  void load();
  
  void update(float dt);

  void render(SDL_Renderer* r);

  Map( ResourceManager* resManager );
  ~Map();
  

};
