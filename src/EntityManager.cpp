#include "EntityManager.h"

#include "Collider.h"


void EntityManager::addEntity(Entity* entity) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (!entities[i]) {
      entities[i] = entity;
    }
  }
}

void EntityManager::update(float dt) {

  /*
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if ( i == ImportantEntity::PLAYER ) continue;
    if ( entities[i] && entities[ImportantEntity::PLAYER]->collider->isColliding(entities[i]->collider ) )
      printf("COLLISION OCCURED \n");
  }
*/
  
  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i]->update(dt);
  }
  

}

void EntityManager::render(SDL_Renderer* r) {

}



EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    delete entities[i];
    entities[i] = nullptr;
  }
}
