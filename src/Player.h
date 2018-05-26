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

  const std::string textureName = "resources/ass.bmp";

 public:

  void load() {}
  
  void load(Input& input);

  void proccessInputs();
  
  void update(SDL_Renderer* r);

  void render(SDL_Renderer *r);
  
  Player(SDL_Renderer* r, Vec2* position, int w, int h);
  ~Player();
  

};
