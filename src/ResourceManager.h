#pragma once

#include <SDL.h>
#include <cstdint>
#include <map>

enum Atlas {
  ATLAS_TEST,
  ATLAS_PLAYING
};

class ResourceManager {
 private:

  static const uint32_t MAX_ATLASES = 2;
  
  SDL_Texture* atlasTextures[MAX_ATLASES];

  std::map<std::string, SDL_Rect*>spriteLocations;
  
  
 public:


  SDL_Rect* getSpriteRect( std::string key );
  void addAtlas( SDL_Renderer* r, std::string location, Atlas atlas );
  
  
  
  ResourceManager( SDL_Renderer* r );
  ~ResourceManager();
};
