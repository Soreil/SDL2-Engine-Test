#include "EntityManager.h"
#include "Player.h"
/*
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "PhysicsComponent.h"
*/

#include <typeinfo>

bool EntityManager::init() {

  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i] = nullptr;
  }
  
  return true;
}


void EntityManager::proccessInputs() {
/*
  for (int i = 0; i < MAX_ENTITIES; i++) {
    entities[i]->proccessInputs();
  }
  */
}


void EntityManager::update(SDL_Renderer* r) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i] != nullptr)
      entities[i]->update(r);
    }
}

void EntityManager::render(SDL_Renderer* r) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i] != nullptr)
      entities[i]->render(r);
  }
}


void EntityManager::addEntity(Entity* entity) {
  if ( entities[MAX_ENTITIES - 1] != nullptr ) {
    printf("Entities array is full! Cannot add new entitiy\n");
    delete entity;
  }
  else {
    for (int i = 0; i < MAX_ENTITIES; i++) { 
      if (entities[i] == nullptr) {
	entities[i] = entity;
	printf("Added entity to %d space \n", i);
	break;
      }
    }
  }
}


EntityManager::EntityManager() {
  if ( !init() ) {
    printf("EntityManager init() Failed!\n");
  }
}

EntityManager::~EntityManager() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i]) {
      delete entities[i];
      entities[i] = nullptr;
    }
  }
}
