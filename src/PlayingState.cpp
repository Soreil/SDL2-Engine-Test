#include <iostream>


#include "PlayingState.h"

#include "TestEnt.h"

#include "StateManager.h"

#include "ResourceManager.h"

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
  map->render(r);
  entityManager.render(r);
}



PlayingState::PlayingState(SDL_Renderer* r, ResourceManager* resourceManager ) {
  //player = new Player(r, new Vec2{100,100}, 100, 100 );

  map = new Map(resourceManager, Atlas::ATLAS_TEST);
  
  entityManager.addEntity( new Player(r,resourceManager, 32, 32 , true ) );

  entityManager.addEntity( new TestEnt(r, resourceManager, 400, 400, 128, 128) );


}

PlayingState::~PlayingState() {
  // delete player;
  // player = nullptr;
  delete map;
  map = nullptr;
  
}
