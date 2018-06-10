#pragma once

#include <SDL.h>

#include "State.h"



class MainMenuState : public State {
 public:

  SDL_Texture* menuTexture = nullptr;
  
  bool load(SDL_Renderer* r, StateManager* sm);

  void update(SDL_Renderer* r);

  void render(SDL_Renderer* r);


  MainMenuState();
  ~MainMenuState();
  

};
