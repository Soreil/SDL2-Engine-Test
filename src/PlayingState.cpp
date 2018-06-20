#include <iostream>


#include "PlayingState.h"

#include "TestEnt.h"

#include "StateManager.h"

void PlayingState::onEnterState(GameStateManager* sm) {
  setStateManager(sm);
  timer.start();

  //entity
  
}

void PlayingState::onExitState() {
  releaseStateManager();
}

void PlayingState::handleEvents() {

  const Uint8* keystate = SDL_GetKeyboardState(NULL);

  if ( keystate[SDL_SCANCODE_ESCAPE] ) {
    stateManager->switchState(GameState::MENU);
  }
  
}

void PlayingState::update(float deltaTime) {
  handleEvents();

  // player->update(deltaTime);
  // std::cout << timer.getTicks()/1000.f << std::endl;
   
  entityManager.update(deltaTime);
  
}

void PlayingState::render(SDL_Renderer* r) {
  //player->render(r);
  entityManager.render(r);
}



PlayingState::PlayingState(SDL_Renderer* r) {
  //player = new Player(r, new Vec2{100,100}, 100, 100 );

  entityManager.addEntity( new Player(r, new Vec2{100,100}, 100, 100 ) );

  entityManager.addEntity( new TestEnt(r, 400, 400, 128, 128) );


}

PlayingState::~PlayingState() {
  // delete player;
  // player = nullptr;
}
