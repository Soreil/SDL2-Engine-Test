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
  
  uint16_t MAP_WIDTH;
  uint16_t MAP_HEIGHT;

  std::vector<int> tileMap;
  
  
 public:
  const int tileWidth = 32;
  const int tileHeight = 32;



  int getMapIndex(int x, int y) { return (MAP_WIDTH*y)+x; }

  bool setMapData( std::vector<int> tiles, uint16_t width, uint16_t height );
  
  void load(ResourceManager* resourceManager, Atlas atlas);
  
  void update(float dt);

  void render(SDL_Renderer* r);

  /*
  virtual void interpretAndMapTile( SDL_Renderer* r, SDL_Texture* atlas,
				    std::map<std::string, SDL_Rect*> atlasLocs, SDL_Rect* dstRect );

  */
  void cleanup();
  
  Map( ResourceManager* resManager, Atlas atlas );
  ~Map();
  

};
