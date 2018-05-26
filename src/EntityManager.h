#pragma once

#include <SDL.h>
#include <vector>

#include "Entity.h"


const Uint8 MAX_ENTITIES = 16;

struct EntityManager {

  Entity* entities[16];
  
  bool init();

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);

  void addEntity(Entity* entity);

  EntityManager();
  ~EntityManager();
  
};
