#pragma once

#include <SDL.h>

#include "EntityManager.h"


class World {
 public:

  EntityManager worldEntities;
 
  /*  
    THINGS WORLD NEEDS:

    -TILEMAPS
    
   */
  
 void load(SDL_Renderer* r);

 void proccessInputs();
 
 void update(SDL_Renderer* r);

 void render(SDL_Renderer *r);
  

  World();
  ~World();
  
  
};
