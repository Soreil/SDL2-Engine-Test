#include "PlayingState.h"

#include "Player.h"


bool PlayingState::load(SDL_Renderer* r, StateManager* sm) {
  if ( !r || !sm)
    return false;
  //Add entities to world
  
  testSprite = new Sprite( r, "resources/nene.bmp", NULL, new SDL_Rect{0,0,800,200} );
  //Do load() routine
  world.load(r);
  
  return true;
}

void PlayingState::proccessInputs() {
  world.proccessInputs();
}

void PlayingState::update(SDL_Renderer* r) {

}

void PlayingState::render(SDL_Renderer* r) {
  world.render(r);

  testSprite->render(r);
  
}


PlayingState::PlayingState() {

}

PlayingState::~PlayingState() {

  delete testSprite;
  
}

