#pragma once
#include <SDL.h>


class State {
public:

  virtual void onEnterState() = 0;
  virtual void onExitState() = 0;
  
  virtual void handleEvents() = 0;

  virtual void update(float deltaTime) = 0;
  virtual void render(SDL_Renderer* r) = 0;
  
};
