/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>
#include "Component.h"
#include "Entity.h"


class Player : public Entity {

  void load();

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer *r);
  
  Player();
  ~Player();
  

};
