#pragma once

#include <SDL.h>

#include "State.h"
#include "StateManager.h"
#include "Player.h"
#include "EntityManager.h"

class PlayingState : public State {
 private:

  Input* input_ = nullptr;
  
 public:

  EntityManager entities;

  
  
  bool load(SDL_Renderer* r, StateManager* sm);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);


  PlayingState(Input* input);
  ~PlayingState();
  
  
};
