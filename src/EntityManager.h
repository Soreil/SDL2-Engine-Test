#pragma once

#include "Entity.h"

const uint8_t MAX_ENTITIES = 16;
const uint8_t MAX_MAP_ENTITIES = 128;

enum ImportantEntity {
  PLAYER = 0
};

class EntityManager {
 private:
  Entity* entities[16];
  Entity* mapEntities[MAX_MAP_ENTITIES];
    
 public:

  void addEntity(Entity* entity);
  
  void update(float deltaTime);

  void render(SDL_Renderer* r);

  EntityManager();
  ~EntityManager();
  
  
};
