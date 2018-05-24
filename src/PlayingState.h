#pragma once

#include <SDL.h>

#include "State.h"
#include "World.h"

#include "StateManager.h"

#include "Sprite.h"

class PlayingState : public State {
 public:

  World world;

  Sprite* testSprite = nullptr;
  
  bool load(SDL_Renderer* r, StateManager* sm);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);


  PlayingState();
  ~PlayingState();
  
  
};
