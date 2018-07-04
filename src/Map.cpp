#include "Map.h"

#include "ResourceManager.h"

void Map::load() {

}


void Map::update( float dt ) {

}

void Map::render( SDL_Renderer *r ) {
  if ( !atlasTexture ) {
    printf( "Error in Map.cpp: atlasTexture not loaded!\n" );
  }
  else {
    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = tileWidth;
    dstRect.h = tileHeight;
    
    for ( int y = 0; y < MAP_WIDTH; y++ ) {
      dstRect.x = 0;
      for ( int x = 0; x < MAP_WIDTH; x++ ) {
	if ( map[x][y] == 1 ){
	  SDL_RenderCopy( r, atlasTexture, atlasLocs["purple"] , &dstRect );
	}
	dstRect.x > x*tileWidth ? dstRect.x = 0 : dstRect.x += tileWidth;
      }
      dstRect.y += tileHeight;
    }
  }

}

Map::Map( ResourceManager* resManager ) {
  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    walls[i] = nullptr;
  }

  atlasTexture = resManager->getAtlasTexture(Atlas::ATLAS_TEST);
  resManager->getSpriteLocationsForAtlas( &atlasLocs, Atlas::ATLAS_TEST );
  
}

Map::~Map() {
  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    delete walls[i];
  }

  atlasTexture = nullptr;
}
