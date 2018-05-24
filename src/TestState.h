#pragma once

#include <SDL.h>

#include "State.h"
#include "World.h"

class StateManager;


class TestState : public State {
 public:

  
  World testWorld;  
  
  bool load(SDL_Renderer* r, StateManager* sm );

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);

  TestState();




  ~TestState();
};
