#include "Map.h"

#include "ResourceManager.h"




bool Map::setMapData( std::vector<int> tiles, uint16_t width, uint16_t height ) {

  if ( tiles.size() - (width*height) != 0 ) {
    std::cout << "Error in Map.cpp!: dimensions of map passed to setMapData are incorrect!" << std::endl;
    //set tilemap info to debug default
    tileMap = std::vector<int>{1, 1, 1, 1};
    MAP_WIDTH = 2;
    MAP_HEIGHT = 2;
    return false;
  }
  else {
    tileMap = tiles;
    MAP_WIDTH = width;
    MAP_HEIGHT = height;
    return true;
  }
  
}



void Map::load(ResourceManager* resourceManager, Atlas atlas) {

  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    walls[i] = nullptr;
  }
  
  atlasTexture = resourceManager->getAtlasTexture(Atlas::ATLAS_TEST);
  resourceManager->getSpriteLocationsForAtlas( &atlasLocs, Atlas::ATLAS_TEST );

  if (!setMapData( std::vector<int>{
	                             1, 1, 1, 1,
	                             1, 1, 1, 1,
	                             1, 1, 1, 1,
				     1, 1, 1, 1 }, 8, 2) ) {
    std::cout << "Error setting MapData! Map set to debug default" << std::endl;
    
  }
  
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
	if ( tileMap[getMapIndex(x, y)] == 1 ){
	  //interpretAndRenderMapTile( r, atlasTexture, atlasLocs, &dstRect );
	  SDL_RenderCopy( r, atlasTexture, atlasLocs["green"], &dstRect );
	}
	dstRect.x > x*tileWidth ? dstRect.x = 0 : dstRect.x += tileWidth;
      }
      dstRect.y += tileHeight;
    }
  }
  
}
  

void Map::cleanup() {
  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    delete walls[i];
  }
  atlasTexture = nullptr;

  
  
}


Map::Map( ResourceManager* resManager, Atlas atlas ) {
  load(resManager, atlas);
}

Map::~Map() {
  cleanup();
}

/*
void Map::interpretAndRenderMapTile( SDL_Renderer* r, SDL_Texture* atlasTexture,
				     SDL_Rect* atlasLocation, SDL_Rect* destinationRect ) {

  

				     }
*/
