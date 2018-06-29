#include "Map.h"

void Map::load() {

}


void Map::update( float dt ) {

}

void Map::render( SDL_Renderer *r ) {

}

Map::Map() {
  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    walls[i] = nullptr;
  }
  
}

Map::~Map() {
  for ( int i = 0; i < MAX_WALL_COLLIDERS; i++  ) {
    delete walls[i];
  }
}
