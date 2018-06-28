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
      if ( entities[ImportantEntity::PLAYER]->collider->isColliding( entities[i]->collider ) ) {
	
	projectionVec = SAT::getCollisionVector( entities[ImportantEntity::PLAYER]->collider->sat_box,
						 entities[i]->collider->sat_box );




	if ( projectionVec.x == 0 ) {
	  projectionVec.y > 0 ? printf("Colliding from bottom\n") : printf("Colliding from top\n");
	}
	else if (projectionVec.y == 0) {
	   projectionVec.x > 0 ? printf("Colliding from right\n") : printf("Colliding from left\n");
	}
	
	
	 printf("Collsion! Proj.Vec {X:%d, Y:%d}\n", projectionVec.x, projectionVec.y);
	 
	 printf("SAT_RECT CENTER: X:%d  Y:%d\n", entities[i]->collider->sat_box->w/2,
		                                 entities[i]->collider->sat_box->h/2 );
	 
	 
      }
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
    if (entities[i])
      entities[i]->update(dt);
  }

  resolveCollisions();

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
