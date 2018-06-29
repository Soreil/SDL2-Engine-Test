#include "EntityManager.h"

#include "Collider.h"

#include "Physics.h"

#include "SAT.h"


void EntityManager::addEntity(Entity* entity) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (!entities[i]) {
      entities[i] = entity;
      break;
    }
  }

  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i]) {
      printf("%d has an entity\n", i);
    }
    else {
      printf("%d is a nullptr\n", i);
    }
  }
  
}



void EntityManager::resolveCollisions() {
  Vec2 projectionVec;
  
  for ( int i = 1; i < MAX_ENTITIES; i++ ) {

    if ( entities[i] && entities[i]->collider ) {
      if ( Physics::isColliding( entities[ImportantEntity::PLAYER]->collider, entities[i]->collider )  ) {
	
	projectionVec = SAT::getCollisionVector( entities[ImportantEntity::PLAYER]->collider->sat_box,
						 entities[i]->collider->sat_box );

	entities[ImportantEntity::PLAYER]->position =
	  entities[ImportantEntity::PLAYER]->position + projectionVec;
	 
      }
    }    
  }
}


void EntityManager::update(float dt) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i]) {
      entities[i]->update(dt);

      if (entities[i]->collider)
	entities[i]->collider->update( entities[i] );
      
    }
  }
  resolveCollisions();

  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i]) {
      if ( entities[i]->sprite )
	entities[i]->sprite->update( entities[i] );
    }
  }
}



void EntityManager::render(SDL_Renderer* r) {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i])
      entities[i]->render(r);
  }
}



EntityManager::EntityManager() {

}

EntityManager::~EntityManager() {
  for (int i = 0; i < MAX_ENTITIES; i++) {
    delete entities[i];
    entities[i] = nullptr;
  }
}
