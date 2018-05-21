#include "World.h"
#include "Player.h"


void World::load(SDL_Renderer* r) {
  // worldEntities.load();
  worldEntities.addEntity( Player::createPlayer(r) );
  
}

void World::proccessInputs() {
  worldEntities.proccessInputs();
}

void World::update() {
  worldEntities.update();
}

void World::render(SDL_Renderer *r) {
  worldEntities.render(r);
}
  

World::World() {

}

World::~World() {

}
