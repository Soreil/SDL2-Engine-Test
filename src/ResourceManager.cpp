#include "ResourceManager.h"

#include "Graphics.h"



SDL_Rect* ResourceManager::getSpriteRect( std::string key ) {
  if ( spriteLocations[key] )
    return spriteLocations[key];

  return nullptr;
}



void ResourceManager::addAtlas( SDL_Renderer* r, std::string location, Atlas atlas ) {
  if ( atlasTextures[atlas] != nullptr ) {
    printf("Error loading atlas texture '%s'; Atlas already exists or is filled with junk data!\n");
  }
  else {
    atlasTextures[atlas] = Graphics::loadTexture( r, location );
  }
}





ResourceManager::ResourceManager( SDL_Renderer* r ) {
  for ( int i = 0; i < MAX_ATLASES; i++ ) {
    atlasTextures[i] = nullptr;
  }

  addAtlas(r, "resources/testAtlas.bmp", Atlas::ATLAS_TEST );

  spriteLocations["purple"] = new SDL_Rect{ 0,  0, 32,  32 };
  spriteLocations["green"]  = new SDL_Rect{ 32, 0, 32,  32 };
  spriteLocations["red"]    = new SDL_Rect{ 0,  32, 32, 32 };
  spriteLocations["blue"]   = new SDL_Rect{ 32, 32, 32, 32 };   


}


ResourceManager::~ResourceManager() {
  for ( int i = 0; i < MAX_ATLASES; i++ ) {
    delete atlasTextures[i];
    atlasTextures[i] = nullptr;
  }
  for ( auto p : spriteLocations ) {
    if ( p.second != nullptr )
      delete p.second;
    p.second != nullptr;
    
  }
}
