/*
  SWEETSBEATS 2018
*/
#pragma once
#include <SDL.h>

#include "Entity.h"
#include "Input.h"


class Player : public Entity {
 private:
  Input* input_ = nullptr;

 public:

  void load() {}
  
  void load(Input& input);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer *r);
  
  Player();
  ~Player();
  

};
