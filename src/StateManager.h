#pragma once
#include "State.h"

#include <vector>

class ResourceManager;

enum GameState {
  STARTUP,
  MENU,
  PLAYING,
  SHUTDOWN,
  TRANSITION
};

const uint8_t STATE_COUNT = 5;

class GameStateManager {
 private:

  State* states[STATE_COUNT];
  
  State* currStatePtr  = nullptr;
  State* prevStatePtr = nullptr;

  GameState currState;
  GameState prevState;

 public:

  void switchState(GameState newState);
  /*
    if (currentState != newState) {
      currentState = newState;
      currentState->onEnter();
    }
    else {
      printf("err...");
    }
   */

  void update(float deltaTime);

  void render(SDL_Renderer *r);

  
  GameStateManager(SDL_Renderer* r, ResourceManager* resourceManager);
  ~GameStateManager();
  
};
