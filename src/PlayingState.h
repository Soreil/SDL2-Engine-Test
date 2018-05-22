#pragma once

#include <SDL.h>

#include "State.h"
#include "World.h"

class PlayingState : public State {
 public:

  World world;
  
  
  void load(SDL_Renderer* r);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);


  PlayingState();
  ~PlayingState(){}
  
  
};
