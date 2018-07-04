#include "ResourceManager.h"

#include "Graphics.h"


/*
SDL_Rect* ResourceManager::getSpriteRect( std::string key ) {
  if ( spriteLocations[key] )
    return spriteLocations[key];

  return nullptr;
  }
*/



void ResourceManager::addAtlas( SDL_Renderer* r, std::string location, Atlas atlas ) {
  if ( atlasTextures[atlas] != nullptr ) {
    printf("Error loading atlas texture '%s'; Atlas already exists or is filled with junk data!\n",
	   location.c_str() );
  }
  else {
    atlasTextures[atlas] = Graphics::loadTexture( r, location );
  }
}


SDL_Texture* ResourceManager::getAtlasTexture( Atlas atlas ) {
  if ( atlasTextures[atlas] )
    return atlasTextures[atlas];
}

/*
SDL_Rect* ResourceManager::getSpriteLocation( std::string spriteName,  Atlas atlas ) {
  if ( spriteLocations[spriteName] ) {
    return spriteLocations[spriteName];
  }
  else {
    printf(" Error in ResourceManager.cpp: Couldn't find sprite location for '%s'!\n", spriteName.c_str() );
    return nullptr;
  }
  }
*/

SDL_Rect* ResourceManager::getSpriteLocation( std::string spriteName,  Atlas atlas ) {
  if ( spriteLocations[atlas][spriteName] ) {
    return spriteLocations[atlas][spriteName];
  }
  else {
    printf(" Error in ResourceManager.cpp: Couldn't find sprite location for '%s'!\n", spriteName.c_str() );
  }
}


void ResourceManager::getSpriteLocationsForAtlas( std::map<std::string, SDL_Rect*>* locMap, Atlas atlas ) {
  for ( auto p : spriteLocations[atlas] ) {
    locMap->insert( std::pair<std::string, SDL_Rect*>(p.first, p.second) );
  }
}

ResourceManager::ResourceManager( SDL_Renderer* r ) {
  for ( int i = 0; i < MAX_ATLASES; i++ ) {
    atlasTextures[i] = nullptr;
  }

  addAtlas(r, "resources/testAtlas.bmp", Atlas::ATLAS_TEST );
  
  spriteLocations[Atlas::ATLAS_TEST]["purple"] = new SDL_Rect{ 0,  0, 32,  32 };
  spriteLocations[Atlas::ATLAS_TEST]["green"]  = new SDL_Rect{ 32, 0, 32,  32 };
  spriteLocations[Atlas::ATLAS_TEST]["red"]    = new SDL_Rect{ 0,  32, 32, 32 };
  spriteLocations[Atlas::ATLAS_TEST]["blue"]   = new SDL_Rect{ 32, 32, 32, 32 };   

  addAtlas( r, "resources/menuTexture.bmp", Atlas::ATLAS_MENU_TEXTURE );

  spriteLocations[Atlas::ATLAS_MENU_TEXTURE]["menuTexture"] = new SDL_Rect{0, 0, 800, 600};
  
}


ResourceManager::~ResourceManager() {
  for ( int i = 0; i < MAX_ATLASES; i++ ) {
    delete atlasTextures[i];
    atlasTextures[i] = nullptr;
  }
  
  for ( int i = 0; i < MAX_ATLASES; i++ ) {
    for ( auto p : spriteLocations[i] ) {
      if ( p.second != nullptr ) {
	delete p.second;
	p.second = nullptr;
      }
    }
  }
  
}
