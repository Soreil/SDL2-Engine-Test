#include "EntityManager.h"

#include "Collider.h"


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

  /*
    
    if a collision is detected using AABB
    
    auto displacement = getCollisionArea( entity );

    CollisionDirection dir = getCollisionDirection( player.collider.x, player.collider.y, 
                                                   ent.collider.x, ent.collider.y, 
						   displacement.x, displacement.y  );
    

    resolveCollision( player, ent, dir, displacement )
    
    
   */
  
  
}




void EntityManager::update(float dt) {

  /*
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if ( i == ImportantEntity::PLAYER ) continue;
    if ( entities[i] && entities[ImportantEntity::PLAYER]->collider->isColliding(entities[i]->collider ) )
      printf("COLLISION OCCURED \n");
  }
*/

  for ( int i = 0; i < MAX_ENTITIES; i++ ) {
    if (i == ImportantEntity::PLAYER) continue;
    if (entities[i]) {
      
      if ( entities[i]->collider ) {
	if ( entities[i]->collider )
	if (entities[ImportantEntity::PLAYER]->collider ) {
	  if ( entities[ImportantEntity::PLAYER]->collider->isColliding( entities[i]->collider ) ) {
	    
	    entities[ImportantEntity::PLAYER]->collider->getCollisionArea( entities[i]->collider);

	  }
	}
	else {
	   printf("Player doesn't have a collider! \n");
	}	
      }
    }
  }
  
  
  
  
  for (int i = 0; i < MAX_ENTITIES; i++) {
    if (entities[i])
      entities[i]->update(dt);
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
