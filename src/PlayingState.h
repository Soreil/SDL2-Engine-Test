#pragma once

#include <SDL.h>

#include "State.h"
#include "StateManager.h"
#include "Player.h"
#include "EntityManager.h"

class PlayingState : public State {
 public:

  EntityManager entities;

  
  
  bool load(SDL_Renderer* r, StateManager* sm);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);


  PlayingState();
  ~PlayingState();
  
  
};
