#include "StateManager.h"

#include "MenuState.h"

#include <stdio.h>

void GameStateManager::switchState(GameState newState) {
  if (currState != newState) {
    //Exiting current state
    currStatePtr->onExitState();
    
    //set prev state and pointer to current state
    prevStatePtr = currStatePtr;
    prevState = currState;
    //set current state to new state
    currStatePtr = states[(int)newState];
    currState = newState;

    //entering new state
    currStatePtr->onEnterState();
  }
  else {
    printf("Failed to switch states, state: %d is already the current state!\n", (int)currState );
  }
}

void GameStateManager::update() {
  currStatePtr->update();
}


void GameStateManager::render() {
  currStatePtr->render();
}

GameStateManager::GameStateManager() {

  //clean the array at init
  for (int i = 0; i < STATE_COUNT; i++) {
    states[i] = nullptr;
  }
  
  //states[GameState::STARTUP]  = new MenuState();
  states[GameState::MENU]     = new MenuState();
  //states[GameState::PLAYING]  = new MenuState();
  //states[GameState::SHUTDOWN] = new MenuState();
  
}

GameStateManager::~GameStateManager() {
  for (int i = 0; i < STATE_COUNT; i++) {
    if (states[i])
      delete states[i];
    states[i] = nullptr;
  }
}
