#pragma once

#include <SDL.h>

#include "State.h"
#include "World.h"


class TestState : public State {
 public:

  World testWorld;  
  
  void load(SDL_Renderer* r);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);

  TestState();




  ~TestState() {}

};
