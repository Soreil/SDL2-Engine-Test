#include "World.h"
#include "Player.h"


void World::load(SDL_Renderer* r) {
   worldEntities.init();
  
}

void World::proccessInputs() {
  worldEntities.proccessInputs();
}




//void e.resolveCollisions {
  /*
  for ( auto ents : collidingEnts ) {
    e.setPosition(  e.position + getCollisionArea()   );
  }
*/



//void World::proccessCollisions() {
  /*
  auto ents = worldEntities.getEntitiesWithComponentType<PhysicsComponent>();
  
  for ( auto e : ents ) {
    if e.isColliding( ents ) {
	e.resolveCollisions();


      }
    
  }
  */
  
//}


void World::update(SDL_Renderer* r) {
  worldEntities.update(r);

  //Do collision routine around here maybe?


  
  
}

void World::render(SDL_Renderer *r) {
  worldEntities.render(r);
}
  

World::World() {

}

World::~World() {

}
