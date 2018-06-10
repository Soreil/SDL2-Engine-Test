#pragma once
#include <SDL.h>
#include <stdio.h>

#include "StateManager.h"


class State {
 public:

  StateManager* stateManager = nullptr;

  bool loaded = false;

  virtual bool load(SDL_Renderer* r, StateManager* sm ) = 0;
  
  virtual void update(SDL_Renderer* r) = 0;

  virtual void render(SDL_Renderer* r) = 0;

  State(){}
  ~State(){}
  

}; 


