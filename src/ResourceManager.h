#pragma once

#include <SDL.h>
#include <cstdint>
#include <map>

enum Atlas {
  ATLAS_TEST,
  ATLAS_MENU_TEXTURE
};

class ResourceManager {
 private:

  static const uint32_t MAX_ATLASES = 2;
  
  SDL_Texture* atlasTextures[MAX_ATLASES];

  std::map<std::string, SDL_Rect*>spriteLocations[MAX_ATLASES];
  
  
 public:


  //SDL_Rect* getSpriteRect( std::string key );

  SDL_Texture* getAtlasTexture( Atlas atlas );

  void addAtlas( SDL_Renderer* r, std::string location, Atlas atlas );

  SDL_Rect* getSpriteLocation( std::string spriteName,  Atlas atlas );

  void getSpriteLocationsForAtlas( std::map<std::string, SDL_Rect*>* locMap, Atlas atlas );
  
  ResourceManager( SDL_Renderer* r );
  ~ResourceManager();
};
