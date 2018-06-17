#pragma once
#include <SDL.h>

class GameStateManager;

class State {
 public:
  GameStateManager* stateManager = nullptr;

  void setStateManager(GameStateManager* stateManager) {
    this->stateManager = stateManager;
  }

  void releaseStateManager() {
    stateManager = nullptr;
  }

  virtual void onEnterState(GameStateManager* stateManager) = 0;
  virtual void onExitState() = 0;
  
  virtual void handleEvents() = 0;

  virtual void update(float deltaTime) = 0;
  virtual void render(SDL_Renderer* r) = 0;
  
};
