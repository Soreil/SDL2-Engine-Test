#pragma once

#include <SDL.h>
#include <cstdint>
#include <map>

class ResourceManager {
 private:

  const uint32_t MAX_TEXTURES = 32;
  
  SDL_Texture* textures[MAX_TEXTURES];
  std::map<std::string, Sprite*> texture;
  
  
 public:


  SDL_Texture* getTexture( std::string key );
  
  
  ResourceManager();
  ~ResourceManager();
};
