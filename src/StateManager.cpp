#include "StateManager.h"

#include "State.h"
#include "TestState.h"

#include "PlayingState.h"

#include "MainMenuState.h"

bool StateManager::init(SDL_Renderer* r) {
  renderer = r;

  //Load default state (For testing purposes it's TestState)

  // stateContainer new TestState 
  //stateContainer.push_back( new PlayingState() );

  for ( int i = 0; i < STATE_COUNT; i++  ) {
    states[i] = nullptr;
  }
  
  states[ GameState::mainMenu ]    = new MainMenuState();
  states[ GameState::playing ] = new PlayingState();
  states[ GameState::test ]    = new TestState();
  
  //currentState = stateContainer[ GameState::testState ];

  currentState = states [ GameState::mainMenu ];

  
  
}



void StateManager::load() {
  
  /* if (currentState)
     currentState->load(renderer);
  */

  for ( int i = 0; i < STATE_COUNT; i++ ) {
    states[i]->load(renderer, this);
  }

  
}


void StateManager::proccessInputs() {
  if (currentState)
    currentState->proccessInputs();
  
}

void StateManager::update() {
  if (currentState)
    currentState->update(renderer);
}

void StateManager::render() {
  if (currentState)
    currentState->render(renderer);
}


void StateManager::switchState(int state) {

  if ( currentState != states[state] ) {
    currentState = states[state];
  } else {
    printf("Cannot switch states! new state == current State!\n");
  }
  
}


StateManager::StateManager() {

}


StateManager::~StateManager() {
  currentState = nullptr;
  renderer = nullptr;
    

  for ( int i = 0; i < STATE_COUNT; i++  ) {
    if (states[i])
      delete states[i];
    states[i] = nullptr;
  }

  
  
}




