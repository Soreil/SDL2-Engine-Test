#include "EntityManager.h"
#include "Player.h"
/*
#include "GraphicsComponent.h"
#include "InputComponent.h"
#include "PlayerInputComponent.h"
#include "PhysicsComponent.h"
*/

#include <typeinfo>

void EntityManager::init(SDL_Renderer* r) {
  addEntity( Player::createPlayer( r ) );

   for (auto e : entities ) {
     printf("+1 entity\n");
     for (auto c :e->components ) {
       printf( "+1 component\n" );
       printf("Type: %s\n", typeid(*c).name() );
     }
   }
}


void EntityManager::proccessInputs() {
  for (auto e : entities ) {
    if ( e->hasComponent<PlayerInputComponent>() ) {
      e->getComponent<PlayerInputComponent>()->update(e);
    }
  }
}


void EntityManager::update() {

  for ( auto e : entities ) {

    // check for each system in order
    /*
    if ( e->hasComponent<InputComponent>() ) {
      e->getComponent<InputComponent>()->update();
    }
    */

    if ( e->hasComponent<PhysicsComponent>() ) {
      e->getComponent<PhysicsComponent>()->update(e);
    }
    
    
  }
  
}

void EntityManager::render(SDL_Renderer* r) {
  for (auto e : entities) {
    if ( e->hasComponent<GraphicsComponent>() ) {
      e->getComponent<GraphicsComponent>()->update(e);
    }
  }
}

template <typename T>
std::vector<Entity*> EntityManager::getEntitiesWithComponentType() {
  std::vector<Entity*> ents;
  for (auto e : entities) {
    if ( e->hasComponent<T>() ) {
      ents.push_back(e);
    }
  }
  return ents;
}

void EntityManager::addEntity(Entity* entity) {
  if (entity) {
    entities.push_back(entity);
  }
  else {
    printf("Null entity! ERROR!\n");
  }
}


/*
EntityManager::EntityManager() {

}*/

EntityManager::~EntityManager() {
  for (auto e : entities)
    delete e;
}
