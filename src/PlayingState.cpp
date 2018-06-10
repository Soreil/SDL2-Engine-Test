#include "PlayingState.h"

#include "Player.h"


bool PlayingState::load(SDL_Renderer* r, StateManager* sm) {
  if ( !r || !sm)
    return false;

  entities.init();
  
  //Add entities to world
  entities.addEntity( new Player(r, new Vec2{32,32}, 64, 64, input_ ) );
  
  return true;
}

void PlayingState::update(SDL_Renderer* r) {
  entities.update(r);
}

void PlayingState::render(SDL_Renderer* r) {
  entities.render(r);  
}


PlayingState::PlayingState(Input* input ) {
  input_ = input;
}

PlayingState::~PlayingState() {
  
}

