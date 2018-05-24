#include "PlayingState.h"

#include "Player.h"


void PlayingState::load(SDL_Renderer* r, StateManager* sm) {


  //Add entities to world

  world.worldEntities.addEntity( Player::createPlayer(r) );
  
  
  //Do load() routine
  world.load(r);
  

}

void PlayingState::proccessInputs() {

}

void PlayingState::update(SDL_Renderer* r) {

}

void PlayingState::render(SDL_Renderer* r) {
  world.render(r);
}


PlayingState::PlayingState() {

}

PlayingState::~PlayingState() {

}

