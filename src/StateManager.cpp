#include "StateManager.h"

#include "MenuState.h"
#include "PlayingState.h"

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
    currStatePtr->onEnterState(this);
  }
  else {
    printf("Failed to switch states, state: %d is already the current state!\n", (int)currState );
  }
}

void GameStateManager::update(float deltaTime) {
  if (currStatePtr)
    currStatePtr->update(deltaTime);
}


void GameStateManager::render(SDL_Renderer* r) {
  if (currStatePtr)
    currStatePtr->render(r);
}

GameStateManager::GameStateManager(SDL_Renderer* r) {
  //clean the array at init
  for (int i = 0; i < STATE_COUNT; i++) {
    states[i] = nullptr;
  }
  
  //states[GameState::STARTUP]  = new MenuState();
  states[GameState::MENU]     = new MenuState(r);
  states[GameState::PLAYING]  = new PlayingState();
  //states[GameState::SHUTDOWN] = new MenuState();


  //SET DEFAULT STATE (IN THIS CASE MENUSTATE)
  currStatePtr = states[GameState::MENU];
  currStatePtr->onEnterState(this);
  
}

GameStateManager::~GameStateManager() {
  for (int i = 0; i < STATE_COUNT; i++) {
    if (states[i])
      delete states[i];
    states[i] = nullptr;
  }
}
