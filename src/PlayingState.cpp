#include "PlayingState.h"

#include "Player.h"


void PlayingState::load(SDL_Renderer* r, StateManager* sm) {


  //Add entities to world

  world.worldEntities.addEntity( Player::createPlayer(r) );
  
  
  //Do load() routine
  world.load(r);
  

  testSprite = new Sprite( r, "resources/nene.bmp", new Vec2{100,100}, NULL );
  
}

void PlayingState::proccessInputs() {

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

